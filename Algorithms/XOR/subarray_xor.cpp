#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;

/*  Given an array of positive integers you have to print the number of subarrays
    whose XOR is less than K.

    Input:          Output: 3
    1
    5 2
    4 1 3 2 7


    xor(i,j) means XOR of elements from indexed i to j of an Array
    XOR(i,j) = XOR(1,i-1)^XOR(1,j);

    This can be proved as:
    A^A = 0     & A^0 = A;
    Hence if we XOR the total XOR from 1 to j with total XOR from 1 to i-1 ,
    it will nullify the effect  of XOR(1,i-1) in XOR(1,j) and the remaining
    XOR will be XOR(i,j);
*/

uint next_int() {
	register uint res = 0;
	register char ch;
	while((ch = getc_unlocked(stdin)) < '0') {}
	do {
		res *= 10;
		res += (ch - '0');
	} while((ch = getc_unlocked(stdin)) >= '0');
	return res;
}

class Node {
    public:
        int lCount,rCount;
        Node *lChild,*rChild;

        Node() {
            lCount = rCount = 0;
            lChild = rChild = NULL;
        }
};

void addBit(Node *root,int n) {
    for(int i = 20; i >= 0; i--) {
        int x= (n>>i) & 1;

        if(x) {
            root->rCount++;

            if(root->rChild == NULL)
                root->rChild = new Node();

            root = root->rChild;
        } else {
            root->lCount++;

            if(root->lChild == NULL)
                root->lChild = new Node();
            root = root->lChild;
        }
    }
}

int query(Node *root,int n,int k) {
    if(root == NULL) return 0;

    int res = 0;

    for(int i = 20; i >= 0; i--) {
        bool ch1=(k>>i) & 1;
        bool ch2=(n>>i) & 1;

        if(ch1) {
            if(ch2) {
                res+=root->rCount;

                if(root->lChild == NULL) return res;
                root = root->lChild;
            } else {
                res+=root->lCount;

                if(root->rChild == NULL) return res;
                root = root->rChild;
            }
        } else {
            if(ch2) {
                if(root->rChild == NULL) return res;
                root= root->rChild;
            } else {
                if(root->lChild == NULL) return res;
                root= root->lChild;
            }
        }
    }
    return res;
}

int main() {
    int t;
    //scanf("%d",&t);
    t = next_int();

    while(t--) {
        int n,k;

        n = next_int();
        k = next_int();

        int temp,temp1,temp2=0;
        Node *root = new Node();
        addBit(root,0);
        long long total =0;

        for(int i = 0; i < n; i++) {
            temp = next_int();
            temp1= temp2^temp;
            total+=(long long)query(root,temp1,k);
            addBit(root , temp1);
            temp2 = temp1;
        }

        printf("%lld\n",total);
    }
    return 0;
}
