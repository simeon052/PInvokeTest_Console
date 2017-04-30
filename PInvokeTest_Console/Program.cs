using System;
using System.Runtime.InteropServices;

namespace PInvokeTest_Console
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            Console.WriteLine($"Answer : {NativeLib.Add(1,1).ToString()}");

        }
    }

    internal class NativeLib
    {
        [DllImport("Win32CppLib", CallingConvention = CallingConvention.Cdecl)]
        private static extern int add(int a, int b);
 
        [DllImport("Win32CppLib")]
        private static extern IntPtr addstr(ref string src, int length);

        [DllImport("Win32CppLib")]
        private static extern void replacestr(ref string src, int length);

        public static int Add(int a, int b)
        {
            return NativeLib.add(a,b);
        }

        public static string Replacestr(string src)
        {
            string dst = src;
            NativeLib.replacestr(ref dst, dst.Length);
            return dst;
        }

        public static string Addstr(string src)
        {
            string dst = src;
            var result = NativeLib.addstr(ref dst, dst.Length);
            var resultStr = Marshal.PtrToStringAnsi(result);
            // TODO : C++ module allocated some memory, must be freed.
            Marshal.FreeCoTaskMem(result);
            return resultStr;
        }
    }

}