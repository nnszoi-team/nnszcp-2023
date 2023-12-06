using System;
using System.IO;
namespace ProgramApplication
{

    class Program
    {
        class Splay
        {
            public int root = 0;
            public int INF = 0x3f3f3f3f;
            public int tot = 0;
            class nodes
            {
                public int val = 0;
                public int fa = 0;
                public int siz = 0;
                public int[] son = new int[2];
                public nodes()
                {
                    val = 0;
                    fa = 0;
                    siz = 0;
                    son = new int[2];
                }
            };
            nodes[] node = new nodes[400005];
            bool check(int k)
            {
                return node[node[k].fa].son[1] == k;
            }
            void maintain(int k)
            {
                node[k].siz = node[node[k].son[0]].siz + node[node[k].son[1]].siz + 1;
            }
            void rotate(int k)
            {
                int father = node[k].fa;
                int grandFather = node[father].fa;
                int inv = check(k) ? 1 : 0;
                node[grandFather].son[check(father) ? 1 : 0] = k;
                node[node[k].son[inv ^ 1]].fa = father;
                node[father].son[inv] = node[k].son[inv ^ 1];
                node[k].son[inv ^ 1] = father;
                node[k].fa = grandFather;
                node[father].fa = k;
                maintain(father);
                maintain(k);
            }
            void rotateTo(int k, int goal)
            {
                while (node[k].fa != goal)
                {
                    if (node[node[k].fa].fa != goal)
                    {
                        rotate(check(k) ^ check(node[k].fa) ? node[k].fa : k);
                    }
                    rotate(k);
                }
                if (goal == 0)
                {
                    root = k;
                }
            }
            public int size()
            {
                return tot;
            }
            public void insert(int value = 0)
            {
                int k = root;
                int father = 0;
                while (k != 0 && node[k].val != value)
                {
                    father = k;
                    k = node[k].son[(value > node[k].val) ? 1 : 0];
                }

                if (k == 0)
                {
                    k = ++tot;

                    node[k].fa = father;
                    if (father != 0)
                    {
                        node[father].son[(value > node[father].val) ? 1 : 0] = k;
                    }
                    node[k].siz = 1;
                    node[k].val = value;
                }
                rotateTo(k, 0);
            }
            public int getRankByValue(int query)
            {
                int k = root, rak = 1, last = 0;
                while (k != 0)
                {
                    if (query <= node[k].val)
                    {
                        last = k;
                        k = node[k].son[0];
                    }
                    else
                    {
                        rak += node[node[k].son[0]].siz + 1;
                        k = node[k].son[1];
                    }
                }
                if (last != 0)
                {
                    rotateTo(last, 0);
                }
                return rak;
            }
            public Splay()
            {
                root = 0;
                tot = 0;
                INF = 0x3f3f3f3f;
                for (int i = 0; i < 400000; ++i)
                {
                    node[i] = new nodes();
                }
                insert(INF);
                insert(-INF);
            }
        }
        static void Main(string[] args)
        {
            string[] inputStr = Console.ReadLine().Split();
            int n = Convert.ToInt32(inputStr[0]);
            inputStr = Console.ReadLine().Split();
            int[] num = new int[400005];
            for (int i = 0; i < n; ++i)
            {
                num[i + 1] = Convert.ToInt32(inputStr[i]);
            }
            long ans = 0;
            for (int i = 2; i <= n; ++i)
            {
                if (num[1] < num[i])
                {
                    int memory = num[i];
                    num[i] = num[1];
                    num[1] = memory;
                    ans++;
                }
            }
            Splay splay = new Splay();
            splay.insert(num[1]);
            for (int i = 2; i <= n; ++i)
            {
                ans += splay.size() - splay.getRankByValue(num[i] + 1);
                splay.insert(num[i]);
            }
            Console.WriteLine("YES");
            Console.WriteLine(ans);
        }
    }
}
