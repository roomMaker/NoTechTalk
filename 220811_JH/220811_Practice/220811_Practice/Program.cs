using System;

//namespace EventTest
//{
//    delegate void EventHandler(string message);

//    class MyNotifier
//    {
//        public event EventHandler SomethingHappend;

//        public void DoSomething(int number)
//        {
//            int temp = number % 10;

//            if(temp != 0 && temp % 3 == 0)
//            {
//                SomethingHappend(String.Format("{0} : 짝", number));
//            }
//        }
//    }

//    class MainApp
//    {
//        static public void MyHandler(string message)
//        {
//            Console.WriteLine(message);
//        }

//        static void Main(string[] args)
//        {
//            MyNotifier notifier = new MyNotifier();
//            notifier.SomethingHappend += new EventHandler(MyHandler);

//            for (int i = 0; i < 30; i++) 
//            {
//                notifier.DoSomething(i);
//            }
//        }
//    }
//} 


namespace StatementLambda
{
    class MainApp
    {
        delegate string Concatenate(string[] args);

        static void Main(string[] args)
        {
            args = Console.ReadLine().Split(' ');
            Concatenate concat = (arr) =>
            {
                string result = "";
                foreach (string s in arr)
                    result += s;
                
                return result;
            };
            Console.WriteLine(concat(args));
        }
    }
}