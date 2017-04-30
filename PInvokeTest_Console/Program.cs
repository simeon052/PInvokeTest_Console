using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;

namespace PInvokeTest_Console
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            Console.WriteLine($"Add : {NativeLib.Add(1, 1).ToString()}");

            Console.WriteLine($"Replace string : {NativeLib.Replacestr("Test")}");

            Console.WriteLine($"Add string : {NativeLib.Addstr("Test")}");

            NativeLib.GetErrors_cs();
        }
    }
    [StructLayout(LayoutKind.Sequential)]
    internal class Data
    {
        const int buffersize = 32;

        [MarshalAs(UnmanagedType.I4)]
        public int count;
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = buffersize)]
        public Byte[] data;
    }

    internal class NativeLib
    {
        [DllImport("Win32CppLib")]
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
            //            Marshal.FreeCoTaskMem(result);
            return resultStr;
        }

        [DllImport("Win32CppLib")]
        private static extern void GetErrors(IntPtr ptr, int count);

        public static List<Data> GetErrors_cs()
        {
            const int totalCount = 10;
            var a = typeof(Data);
            IntPtr result = Marshal.AllocHGlobal(Marshal.SizeOf<Data>() * 10);
            NativeLib.GetErrors(result, totalCount);

            var pos = new IntPtr(result.ToInt64());
            var resultList = new List<Data>();
            for(int i = 0; i< totalCount; i++)
            {
                resultList.Add((Data)Marshal.PtrToStructure<Data>(pos));
                pos = IntPtr.Add(pos, Marshal.SizeOf<Data>());
                Console.WriteLine($"{resultList.Last<Data>().count.ToString()} - { System.Text.Encoding.ASCII.GetString(resultList.Last<Data>().data)}"); ;
            }

            return resultList;
        }
    }

}