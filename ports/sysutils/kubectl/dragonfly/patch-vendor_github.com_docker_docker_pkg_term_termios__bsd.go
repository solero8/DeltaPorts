--- vendor/github.com/docker/docker/pkg/term/termios_bsd.go.orig	2019-12-06 01:25:03 UTC
+++ vendor/github.com/docker/docker/pkg/term/termios_bsd.go
@@ -1,4 +1,4 @@
-// +build darwin freebsd openbsd netbsd
+// +build darwin freebsd openbsd netbsd dragonfly
 
 package term // import "github.com/docker/docker/pkg/term"
 
