--- vendor/openssl-sys/build/main.rs.orig	2020-05-05 01:35:39 UTC
+++ vendor/openssl-sys/build/main.rs
@@ -204,6 +204,7 @@ See rust-openssl README for more informa
             (3, 0, 0) => ('3', '0', '0'),
             (3, 0, 1) => ('3', '0', '1'),
             (3, 0, _) => ('3', '0', 'x'),
+            (3, 1, _) => ('3', '1', 'x'),
             _ => version_error(),
         };
 
@@ -244,7 +245,7 @@ fn version_error() -> ! {
         "
 
 This crate is only compatible with OpenSSL 1.0.1 through 1.1.1, or LibreSSL 2.5
-through 3.0.x, but a different version of OpenSSL was found. The build is now aborting
+through 3.1.x, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
