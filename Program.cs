using System;
using System.Diagnostics;
using System.ComponentModel;


namespace MyProcessSample
{
    public static class ProcessExtensions
    {
        private static string FindIndexedProcessName(int pid)
        {
            var processName = Process.GetProcessById(pid).ProcessName;
            var processesByName = Process.GetProcessesByName(processName);
            string processIndexdName = null;

            for (var index = 0; index < processesByName.Length; index++)
            {
                processIndexdName = index == 0 ? processName : processName + "#" + index;
                var processId = new PerformanceCounter("Process", "ID Process", processIndexdName);
                if ((int)processId.NextValue() == pid)
                {
                    return processIndexdName;
                }
            }

            return processIndexdName;
        }

        private static Process FindPidFromIndexedProcessName(string indexedProcessName)
        {
            var parentId = new PerformanceCounter("Process", "Creating Process ID", indexedProcessName);
            return Process.GetProcessById((int)parentId.NextValue());
        }

        public static Process Parent(this Process process)
        {
            return FindPidFromIndexedProcessName(FindIndexedProcessName(process.Id));
        }
    }
    class MyProcess
    {
        void BindToRunningProcesses()
        {
            // Get the current process.
            Process currentProcess = Process.GetCurrentProcess();

            // Get all processes running on the local computer.
            Process[] localAll = Process.GetProcesses();
            
            foreach(Process p in localAll)
            {
                Console.WriteLine("=====================================================================");
                Console.WriteLine("     -PID: " + p.Id);
                Console.WriteLine("     -Process Name: " + p.ProcessName);
                Console.WriteLine("     -Process Priority: "+p.BasePriority);
                try
                {
                    Console.WriteLine("     -Parent ID: " + p.Parent().Id);
                }
                catch
                {
                    Console.WriteLine("     Unable to get parent.");
                }
                Console.WriteLine("     -Process threads: ");
                ProcessThreadCollection processThreads = p.Threads;
                int tot_th = 0;
                foreach (ProcessThread thread in processThreads)
                {
                    tot_th++;
                    Console.WriteLine($"        ThreadId: {thread.Id} ThreadPriority: {thread.BasePriority}");
                }
                Console.WriteLine("         Total: "+tot_th+" threads.");
                Console.WriteLine("     -Process modules: ");
                try
                {
                    ProcessModuleCollection modules = p.Modules;
                    int tot = 0;
                    foreach (ProcessModule module in modules)
                    {
                        tot++;
                        Console.WriteLine($"        Name: {module.ModuleName}  MemorySize: {module.ModuleMemorySize} Path: {module.FileName}");
                    }
                    Console.WriteLine("         Total: "+tot+" modules.");
                }
                catch
                {
                    Console.WriteLine("         Unable to get access to modules.");
                }
            }
        }

        static void Main()
        {
            MyProcess myProcess = new MyProcess();
            myProcess.BindToRunningProcesses();
        }
    }
}