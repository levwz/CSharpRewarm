using System;
using System.Collections;
using System.Collections.Generic;
namespace LevwzConsoleApp.Generic
{
    public class LinkedNode<T>
    {

        public LinkedNode(T value){ Value = value; }            
        public LinkedNode<T> Prev { get; internal set; }
        public LinkedNode<T> Next { get; internal set; }

        public T Value { get; internal set; }
    }

    public class LinkedList<T>: IEnumerable<T> 
    {                           //IEnumerable is in System.Collections
                                //IEnumerable<T> is in System.Collections.Generic
                                //IEnumerable<out T>: IEnumerable
                                //IEnumerable.GetEnumerator
        public LinkedList()
        {
            
        }

        public LinkedNode<T> Head { get; set; }
        public LinkedNode<T> Tail { get; set; }

        public void AddToTail(T node)
        {
            LinkedNode<T> current = new LinkedNode<T>(node);
            if(Head == null)
            {
                Head = current;
                Tail = current;
                Head.Next = Tail;
                Tail.Prev = Head;
            }else
            {
                Tail.Next = current;
                current.Prev = Tail;
                Tail = current;
            }

        }

        public IEnumerator<T> GetEnumerator()
        {
            LinkedNode<T> node = Head;
            while(node != null)
            {
                yield return node.Value;
                node = node.Next;
            }
        }

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    }

    public class LinkedListSample{
        public void Test()
        {
            LinkedList<int> list = new LinkedList<int>();

            list.AddToTail(1);
            list.AddToTail(2);
            list.AddToTail(3);
            list.AddToTail(4);
           
            foreach(int x in list)
            {
                Console.WriteLine(x);
            }

            LinkedList<string> objs = new LinkedList<string>();

            objs.AddToTail("1");
        }
    }
}
