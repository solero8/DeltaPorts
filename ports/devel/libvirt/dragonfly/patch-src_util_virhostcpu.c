--- src/util/virhostcpu.c.orig	2020-03-27 21:37:32 UTC
+++ src/util/virhostcpu.c
@@ -32,7 +32,7 @@
 # include <linux/kvm.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__)
 # include <sys/time.h>
 # include <sys/types.h>
 # include <sys/sysctl.h>
@@ -58,7 +58,7 @@ VIR_LOG_INIT("util.hostcpu");
 #define MSR_DEVICE "/dev/cpu/0/msr"
 
 
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__)
 static int
 virHostCPUGetCountAppleFreeBSD(void)
 {
@@ -73,9 +73,9 @@ virHostCPUGetCountAppleFreeBSD(void)
 
     return ncpu;
 }
-#endif /* defined(__FreeBSD__) || defined(__APPLE__) */
+#endif /* defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__) */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 # define BSD_CPU_STATS_ALL 4
 # define BSD_MEMORY_STATS_ALL 4
 
@@ -949,7 +949,7 @@ virHostCPUGetInfo(virArch hostarch G_GNU
  cleanup:
     VIR_FORCE_FCLOSE(cpuinfo);
     return ret;
-#elif defined(__FreeBSD__) || defined(__APPLE__)
+#elif defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__)
     unsigned long cpu_freq;
     size_t cpu_freq_len = sizeof(cpu_freq);
 
@@ -962,7 +962,7 @@ virHostCPUGetInfo(virArch hostarch G_GNU
     *cores = *cpus;
     *threads = 1;
 
-# ifdef __FreeBSD__
+# if defined(__FreeBSD__) || defined(__DragonFly__)
     /* dev.cpu.%d.freq reports current active CPU frequency. It is provided by
      * the cpufreq(4) framework. However, it might be disabled or no driver
      * available. In this case fallback to "hw.clockrate" which reports boot time
@@ -1017,7 +1017,7 @@ virHostCPUGetStats(int cpuNum G_GNUC_UNU
 
         return ret;
     }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
     return virHostCPUGetStatsFreeBSD(cpuNum, params, nparams);
 #else
     virReportError(VIR_ERR_NO_SUPPORT, "%s",
@@ -1032,7 +1032,7 @@ virHostCPUGetCount(void)
 {
 #if defined(__linux__)
     return virHostCPUParseCountLinux();
-#elif defined(__FreeBSD__) || defined(__APPLE__)
+#elif defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__)
     return virHostCPUGetCountAppleFreeBSD();
 #else
     virReportError(VIR_ERR_NO_SUPPORT, "%s",
@@ -1267,7 +1267,7 @@ virHostCPUGetMicrocodeVersion(void)
 
 #if HAVE_LINUX_KVM_H && defined(KVM_GET_MSRS) && \
     (defined(__i386__) || defined(__x86_64__)) && \
-    (defined(__linux__) || defined(__FreeBSD__))
+    (defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__))
 static int
 virHostCPUGetMSRFromKVM(unsigned long index,
                         uint64_t *result)
@@ -1415,4 +1415,4 @@ virHostCPUGetTscInfo(void)
 
 #endif /* HAVE_LINUX_KVM_H && defined(KVM_GET_MSRS) && \
           (defined(__i386__) || defined(__x86_64__)) && \
-          (defined(__linux__) || defined(__FreeBSD__)) */
+          (defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)) */
