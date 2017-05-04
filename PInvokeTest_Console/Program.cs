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

        private IntPtr message;

        private IntPtr next;

        public string messageStr
        {
            get {
                return Marshal.PtrToStringUni(this.message);
            }
        }

        public Data GetNext
        {
            get {
                if (this.next != IntPtr.Zero)
                {
                    return Marshal.PtrToStructure<Data>(this.next);
                }
                else
                {
                    return null;
                }
            }
        }

        public static Data PtrToThis(IntPtr ptr) {
            return Marshal.PtrToStructure<Data>(ptr);
        }

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
        private static extern void GetData(out IntPtr data);

        public static List<Data> GetData()
        {
            var resultList = new List<Data>();

            // Get structure list from C++
            IntPtr data;
            NativeLib.GetData(out data);

            // Add in List at C#
            if (data != IntPtr.Zero)
            {
                var currentData = Data.PtrToThis(data);
                do
                {
                    Console.WriteLine($"{currentData.info} - {currentData.subInfo} - {currentData.messageStr}");
                    resultList.Add(currentData);
                    currentData = currentData.GetNext;
                } while (currentData != null);
                resultList.Remove(null);
            }

            return resultList;
        }
    }

}