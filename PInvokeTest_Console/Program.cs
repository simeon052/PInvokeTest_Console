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

            Console.WriteLine($"Replace string : {NativeLib.Replacestr("Password")}");

            Console.WriteLine($"Add string : {NativeLib.Addstr("Test")}");

            NativeLib.GetData();
        }
    }
    [StructLayout(LayoutKind.Sequential)]
    internal class Data
    {
        [MarshalAs(UnmanagedType.I4)]
        public int info;

        [MarshalAs(UnmanagedType.I4)]
        public int subInfo;

        public IntPtr message;

        public IntPtr next;

    }

    internal class NativeLib
    {
        [DllImport("Win32CppLib")]
        private static extern int add(int a, int b);
 
        [DllImport("Win32CppLib")]
        private static extern void addstr([MarshalAs(UnmanagedType.LPStr)] StringBuilder src, int capacity);

        [DllImport("Win32CppLib")]
        private static extern void replacestr([MarshalAs(UnmanagedType.LPStr)] StringBuilder srcsrc, int length, int capacity);

        public static int Add(int a, int b)
        {
            return NativeLib.add(a,b);
        }

        public static string Replacestr(string src)
        {
            var dst = new StringBuilder(256);
            dst.Append(src);
            NativeLib.replacestr(dst, dst.Length, dst.Capacity);
            return dst.ToString();
        }

        public static string Addstr(string src)
        {
            StringBuilder dst = new StringBuilder(256);
            dst.Append(src);

            NativeLib.addstr(dst, dst.Capacity);
            
            return dst.ToString();
        }

        [DllImport("Win32CppLib", CharSet = CharSet.Unicode)]
        private static extern IntPtr GetData(out IntPtr data);

        public static List<Data> GetData()
        {
            var resultList = new List<Data>();
            IntPtr data;
            var result = NativeLib.GetData(out data);



            resultList.Add((Data)Marshal.PtrToStructure<Data>(data));
            var currentData = resultList.First<Data>();
            if (data != IntPtr.Zero)
            {
                bool loopend = false;
                do
                {
                    Console.WriteLine($"{currentData.info} - {currentData.subInfo} - {Marshal.PtrToStringUni(currentData.message)}");
                    if (currentData.next != IntPtr.Zero)
                    {
                        resultList.Add((Data)(Marshal.PtrToStructure<Data>(currentData.next)));
                        currentData = resultList.Last<Data>();
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