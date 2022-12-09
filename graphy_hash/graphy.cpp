
/*

no arrows both direction,
edges represents cost or distances have values
vertice is a node in graph, conncetion betwween veticies is edge
undirective two way travel
directive travel only one way, in direction of arrow
can have a cost, wiegth, or distance associated with it
Path is a sequence of verticies and edges from source to destination
Cicle is where source and destination is the same

*/
#include <iostream>
#include <stack>
using namespace std;

class graph {
public:
    int n = 5;
    int adj[5][5];  //[n][n]
    bool visit[5];   //inside [n] 
    void init() {
        //for (int i = 0; i < 5;i++) {
        //    for (int j = 0; j < 5; j++) {
        //        adj[i][j] = 0;//load up adj matrix create a function to do it
        //    }
        //}
      
        for (int i = 0;i < 5;i++) {
            visit[i] = false;
        }
    }
    void dfsR(int v) {
        int j;
        init();
        cout << v;
        visit[v] = true;
        for (j = 0; j < 5;j++) {
            if (j != v) {
                if (adj[v][j] == 1) {
                    if (visit[j] == false) {
                        dfsR(j);
                    }
                }
            }
        }
    }
    void depthIt(int v) {
        int j, k, m;
        stack <int> s;
        init();
        s.push(v); // breadth It use queue that it.
        while (s.empty() == false) {//stack is not empty or s.pop()!= curent? dont stack if the same is in there
            m = s.top();
            s.pop();
            cout << m;
            visit[m] = true;
            for (j = 0; j < n; j++) {
                if (j != v) {             //if
                    if ((adj[v][j] == 1) && (visit[j] == false)) {
                        s.push(j);
                    }
                }

            }

        }


}
//hash tables efficiency is o(1)
    /*hash table is a big piece of memory, in which data is placed based on hash index
    hash index is calulated based on property/ characteristics of a data
    collision when we have same index for data entry (hash smah)
    hash function distribute data evenly in memory to avoid collision and have space to allocate collision
    hasj index =((feet*100) +(inches*8)) -400         
                   feet*200          disperser     creates  a gap
        
        HW check where fisrt piece of data land and last land
        aaa low is 0
        zzz top is (25*26^2)+(25*26^1)+(25*26^0) == 17575 
        but we have 73 names
        so u can divide by 100 but still its not as good
        or 200/26 === 8
        we want zzz be about 191 or 192 if we want to fit in table size 200;
        how divide 17575/x =192 and solve for x, u will get assigment. point is that names should come up as nearly sorted or sorted

        so, x = 91.53
        200 size table gives around 40 collisions if
        400 size table gives around 20-30, just half the divisor 91.53/2
        700 gives 15-20 collisions
        allocate memory with strings 
        */
                             

};

int main()
{
    graph* n = new graph;
    n->dfsR(5);

}

