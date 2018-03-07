using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Corno
{

    class Program
    {
        private class No
        {
            public int valor;
            public No esq;
            public No dir;
        }

        static No insere(int valor)
        {
            No temp = new No();
            temp.valor = valor;
            temp.esq = null;
            temp.dir = null;
            return temp;
        }

        static No inserir(No ar, int valor)
        {
            if (ar == null)
            {
                ar = new No();
                ar.valor = valor;
                ar.esq = null;
                ar.dir = null;
            }

            if (ar.valor < valor){
                ar.dir = inserir(ar.dir, valor);
            }
            else if (ar.valor > valor)
            {
                ar.esq = inserir(ar.esq, valor);
            }
                return ar;
        }

        static int imprimirMenor(No ar)
        {
            if (ar.esq == null)
            {
                return ar.valor;
            }
            return imprimirMenor(ar.esq);        
        }

        static int imprimirMaior(No ar)
        {
            if (ar.dir == null)
            {
                return ar.valor;
            }
            return imprimirMenor(ar.dir);
        }

        static void Main(string[] args)
        {
            No arv = null;
            for (int i = 0; i < 5; i++)
            {
                arv = inserir(arv, int.Parse(Console.ReadLine()));
            }
            Console.WriteLine("\nMenor: " + imprimirMenor(arv));
            Console.WriteLine("\nMaior: " + imprimirMaior(arv));
        }
    }
}
