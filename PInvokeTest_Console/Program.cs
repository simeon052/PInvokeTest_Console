using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

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

//            NativeLib.GetErrors_cs();

            NativeLib.GetErrors2_cs();
        }
    }
    [StructLayout(LayoutKind.Sequential)]
    internal class Data
    {
        [MarshalAs(UnmanagedType.I4)]
        public int info;

        [MarshalAs(UnmanagedType.I4)]
        public int subInfo;

        public IntPtr messasg;

        public IntPtr next;

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
            return resultStr;
        }

        [DllImport("Win32CppLib", CharSet = CharSet.Unicode)]
        private static extern IntPtr GetData(out IntPtr data);

        public static List<Data> GetErrors2_cs()
        {
            var resultList = new List<Data>();
            IntPtr data;
            var result = NativeLib.GetData(out data);


            var stData = (Data)Marshal.PtrToStructure<Data>(data);
            if (data != IntPtr.Zero)
            {
                bool loopend = false;
                do
                {
                    Console.WriteLine($"{stData.info} - {stData.subInfo} - {Marshal.PtrToStringUni(stData.messasg)}");
                    if (stData.next != IntPtr.Zero)
                    {
                        stData = (Data)(Marshal.PtrToStructure<Data>(stData.next));
                    }
                    else
                    {
                        loopend = true;

                    }
                } while (loopend != true);
            }

            return resultList;
        }
    }

}