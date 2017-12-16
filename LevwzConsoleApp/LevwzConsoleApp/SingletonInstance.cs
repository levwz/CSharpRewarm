using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LevwzConsoleApp
{
    class SingletonInstance<T> where T : class, new ()
    {
        private static readonly object locker = new object();
        private string name;
        public string Name { get { return name; } set { name = value; } }
        private static SingletonInstance<T> myself = null;

        private static T instance = null;
        public static SingletonInstance<T> GetInstance()
        {
            if (myself != null)
            {
                return myself;
            }
            lock (locker)
            {
                myself = new SingletonInstance<T>();
            }

            return myself;
        }

        public static T CreateInstance()
        {
            if( instance != null)
            {
                return instance;
            }
            lock (locker)
            {
                instance = new T();
            }

            return instance;
        }
    }
}
