#! /usr/local/bin/tclsh8.6

set blurb "OpenSmalltalk on OpenBSD"

#
# Info vomiter for $blurb
#
# Stuart Cassoff
#
# ISC license
#
# 0.1:2017/05/16
#

set mydir  [file normalize [file dirname [info script]]]
set topdir [file normalize [file join $mydir ..]]

set blob [dict create]
set T [list "Squeak VM" "Other VM" "Squeak Image" "Other Image" "Squeak Sources" "Other Sources"]
foreach t $T {
	dict set blob [string map {" " _} [string tolower $t]] [dict create title $t dirs [list]]
}

foreach k [dict keys $blob] {
	set dirs [list]
	foreach dir [glob -nocomplain -tails -dir [file join $topdir $k] ost*] {
		lappend dirs [dict create dir $dir pkgname ""]
	}
	dict set blob $k dirs $dirs
}

dict for {k b} $blob {
	set dirs [list]
	foreach dir [dict get $b dirs] {
		cd [file join $topdir $k [dict get $dir dir]]
		dict set dir pkgname [exec make show=PKGNAME]
		lappend dirs $dir
	}
	dict set blob $k dirs $dirs
}

set O [list]
lappend O $blurb
lappend O ""
lappend O [string cat "Status as of: " [clock format [clock seconds] -gmt 1 -format %Y/%m/%d]]
lappend O ""

if {[file exists [set fn [file join $mydir WHATSUP_BLURB]]]} {
	lappend O [read -nonewline [set f [open $fn]]][close $f]
}
lappend O ""
lappend O ""

lappend O Yields:
lappend O ""

set s ""
set z squeak
foreach k [dict keys $blob $z*] {
	set b [dict get $blob $k]
	append s [dict get $b title] ":" [llength [dict get $b dirs]] "  "
}
lappend O $s
set s ""
set z other
foreach k [dict keys $blob $z*] {
	set b [dict get $blob $k]
	append s [dict get $b title] ":" [llength [dict get $b dirs]] "  "
}
lappend O $s

namespace import ::tcl::mathop::+
lappend O [format \
	"Total VM:%d  Total Image:%d  Total Sources:%d" \
	[+ [llength [dict get $blob squeak_vm      dirs]] [llength [dict get $blob other_vm      dirs]]] \
	[+ [llength [dict get $blob squeak_image   dirs]] [llength [dict get $blob other_image   dirs]]] \
	[+ [llength [dict get $blob squeak_sources dirs]] [llength [dict get $blob other_sources dirs]]] \
]

dict for {k b} $blob {
	lappend O "" [dict get $b title]:
	set z [list]
	foreach dir [dict get $b dirs] {
		lappend z [string range [dict get $dir pkgname] 5 end]
	}
	lappend O [exec column -c 80 <<[join [lsort $z] \n]]
}

puts [join $O \n]

# EOF
