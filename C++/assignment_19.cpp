#include <bits/stdc++.h>

using namespace std;


class AANode {
	public:
		AANode *left, *right;
		int element = 0, level = 0;

		virtual ~AANode() {
			delete left;
			delete right;
		}

        AANode() {
            this->element = 0;
            this->left = this;
            this->right = this;
            this->level = 0;
        }

        AANode(int ele) : AANode(ele, nullptr, nullptr){}

        AANode(int ele, AANode *left, AANode *right) {
            this->element = ele;
            this->left = left;
            this->right = right;
            this->level = 1;
        }
};


class AATree {
	public:
    	AANode *root;
		AANode *nil = new AANode();
		virtual ~AATree() {
			delete root;
		}

        AATree() {
            root = nil;
        }

        bool isEmpty() {
            return root == nil;
        }

        void clear() {
            root = nil;
        }

        void insert(int X) {
            root = insert(X, root);
        }

        AANode *insert(int X, AANode *T) {
            if (T == nil) {
                T = new AANode(X, nil, nil);
            }
            else if (X < T->element) {
                T->left = insert(X, T->left);
            }
            else if (X > T->element) {
                T->right = insert(X, T->right);
            }
            else {
                return T;
            }

            T = skew(T);
            T = split(T);
            return T;
        }

        AANode *skew(AANode *T) {
            if (T == nil) {
                return nil;
            }
            else if (T->left == nil) {
                return T;
            }
            else if (T->left->level == T->level) {
                AANode *L = T->left;
                T->left = L->right;
                L->right = T;
                return L;
            }
            else {
                return T;
            }
        }

        AANode *split(AANode *T) {
            if (T == nil) {
                return nil;
            }
            else if (T->right == nil || T->right->right == nil) {
                return T;
            }
            else if (T->level == T->right->right->level) {
                AANode *R = T->right;
                T->right = R->left;
                R->left = T;

                R->level = R->level + 1;
                return R;
            }
            else {
                return T;
            }
        }

        AANode *decreaseLevel(AANode *T) {
            int shouldBe = std::min(T->left->level, T->right->level) + 1;
            if (shouldBe < T->level) {
                T->level = shouldBe;
                if (shouldBe < T->right->level) {
                    T->right->level = shouldBe;
                }
            }
            return T;
        }

        int countNodes() {
            return countNodes(root);
        }

        int countNodes(AANode *r) {
            if (r == nil) {
                return 0;
            }
            else {
                int l = 1;
                l += countNodes(r->left);
                l += countNodes(r->right);
                return l;
            }
        }

        bool search(int val) {
            return search(root, val);
        }

        bool search(AANode *r, int val) {
            bool found = false;
            while ((r != nil) && !found) {
                int rval = r->element;
                if (val < rval) {
                    r = r->left;
                }
                else if (val > rval) {
                    r = r->right;
                }
                else {
                    found = true;
                    break;
                }
                found = search(r, val);
            }
            return found;
        }

        void inorder() {
            inorder(root);
        }

        void inorder(AANode *r) {
            if (r != nil) {
                inorder(r->left);
                std::wcout << r->element << L" ";
                inorder(r->right);
            }
        }

        void preorder() {
            preorder(root);
        }

        void preorder(AANode *r) {
            if (r != nil) {
                std::wcout << r->element << L" ";
                postorder(r->left);
                postorder(r->right);
            }
        }

        void postorder() {
            postorder(root);
        }

        void postorder(AANode *r) {
            if (r != nil) {
                postorder(r->left);
                postorder(r->right);
                std::wcout << r->element << L" ";
            }
        }

};


int main()
{
    AATree aat; 
    cout << "AATree Tree Test" << endl;          
    char ch;

    do {
        cout << "AATree Operations" << endl;
        cout << "1. insert " << endl;
        cout << "2. search" << endl;
        cout << "3. count nodes" << endl;
        cout << "4. check empty" << endl;
        cout << "5. clear" << endl;

        int choice, temp;
        cin >> choice;
         
        switch(choice) {
            case 1 :
                cout << "Enter integer element to insert: ";
                cin >> temp;
                aat.insert(temp);                     
                break;                          
            case 2 :
                cout << "Enter integer element to search: ";
                cin >> temp;
                cout << "Search result : " << aat.search(temp) << endl;
                break;                                          
            case 3 :
                cout << "Nodes = " << aat.countNodes() << endl;
                break;     
            case 4 :
                cout << "Empty status = " << aat.isEmpty() << endl;
                break;
            case 5 :
                cout << "Tree Cleared" << endl;
                aat.clear();
                break;            
            default :
                cout << "Wrong Entry" << endl;
                break;   
        }

        cout << "Post order : ";
        aat.postorder();
        cout << "\nPre order : ";
        aat.preorder();
        cout << "\nIn order : ";
        aat.inorder();

        cout << "Do you want to continue (Type y or n): ";
        cin >> ch;                        
    }
    while(ch == 'Y'|| ch == 'y');

    return 0;             
}


/* Java Program to Implement AA Tree */
 
// import java.util.Scanner;
// import java.util.NoSuchElementException;

// /** Class AANode **/
// class AANode
// {    
//     AANode left, right;
//     int element, level;    

//     /** Constructor **/    
//     public AANode()
//     {
//         this.element = 0;
//         this.left = this;
//         this.right = this;
//         this.level = 0;
//     }

//     /** Constructor **/    
//     public AANode(int ele)
//     {
//         this(ele, null, null);
//     } 

//     /** Constructor **/
//     public AANode(int ele, AANode left, AANode right)
//     {
//         this.element = ele;
//         this.left = left;
//         this.right = right;
//         this.level = 1;
//     }    
// }

// /** Class AATree **/
// class AATree
// {
//     private AANode root;
//     private static AANode nil = new AANode();

//     /** Constructor **/
//     public AATree()
//     {
//         root = nil;
//     }

//     /** Function to check if tree is empty **/
//     public boolean isEmpty()
//     {
//         return root == nil;
//     }

//     /** Make the tree empty **/
//     public void clear()
//     {
//         root = nil;
//     }

//     /* Functions to insert data */
//     public void insert(int X)
//     {
//         root = insert(X, root);
//     }
//     private AANode insert(int X, AANode T)
//     {
//         if (T == nil)
//             T = new AANode(X, nil, nil);
//         else if ( X < T.element )
//             T.left = insert(X, T.left);
//         else if ( X > T.element)
//             T.right = insert(X, T.right);
//         else
//             return T;

//         T = skew(T);
//         T = split(T);
//         return T;
//     }

//     /** Function Skew **/
//     private AANode skew(AANode T) 
//     {
//         if (T == nil)
//             return nil;
//         else if (T.left == nil)
//             return T;
//         else if (T.left.level == T.level)
//         {
//             AANode L = T.left;
//             T.left = L.right;
//             L.right = T;
//             return L;
//         }         
//         else
//             return T;       
//     }

//     /** Function split **/
//     private AANode split(AANode T) 
//     {
//         if (T == nil)
//             return nil;
//         else if (T.right == nil || T.right.right == nil)
//             return T;
//         else if (T.level == T.right.right.level)
//         {
//             AANode R = T.right;
//             T.right = R.left;
//             R.left = T;

//             R.level = R.level + 1;
//             return R;
//         }
//         else
//             return T;
//     }    

//     /** Function decrease key **/
//     private AANode decreaseLevel(AANode T)
//     {
//         int shouldBe = Math.min(T.left.level, T.right.level) + 1;
//         if (shouldBe < T.level)
//         {
//             T.level = shouldBe;
//             if (shouldBe < T.right.level)
//                 T.right.level = shouldBe;
//         }
//         return T;
//     }

//     /** Functions to count number of nodes **/
//     public int countNodes()
//     {
//         return countNodes(root);
//     }
//     private int countNodes(AANode r)
//     {
//         if (r == nil)
//             return 0;
//         else
//         {
//             int l = 1;
//             l += countNodes(r.left);
//             l += countNodes(r.right);
//             return l;
//         }
//     }
//     /** Functions to search for an element **/
//     public boolean search(int val)
//     {
//         return search(root, val);
//     }
//     private boolean search(AANode r, int val)
//     {
//         boolean found = false;
//         while ((r != nil) && !found)
//         {
//             int rval = r.element;
//             if (val < rval)
//                 r = r.left;
//             else if (val > rval)
//                 r = r.right;
//             else
//             {
//                 found = true;
//                 break;
//             }
//             found = search(r, val);
//         }
//         return found;
//     }
//     /** Function for inorder traversal **/
//     public void inorder()
//     {
//         inorder(root);
//     }
//     private void inorder(AANode r)
//     {
//         if (r != nil)
//         {
//             inorder(r.left);
//             System.out.print(r.element +" ");
//             inorder(r.right);
//         }
//     }
//     /** Function for preorder traversal **/
//     public void preorder()
//     {
//         preorder(root);
//     }
//     private void preorder(AANode r)
//     {
//         if (r != nil)
//         {
//             System.out.print(r.element +" ");
//             preorder(r.left);             
//             preorder(r.right);
//         }
//     }
//     /** Function for postorder traversal **/
//     public void postorder()
//     {
//         postorder(root);
//     }
//     private void postorder(AANode r)
//     {
//         if (r != nil)
//         {
//             postorder(r.left);             
//             postorder(r.right);
//             System.out.print(r.element +" ");
//         }
//     }         
// }

// /** Class AATree **/
// public class AATreeTest
// {
//     public static void main(String[] args)
//     {            
//         Scanner scan = new Scanner(System.in);
//         /** Creating object of AATree **/
//         AATree aat = new AATree(); 
//         System.out.println("AATree Tree Test\n");          
//         char ch;
//         /**  Perform tree operations  **/
//         do    
//         {
//             System.out.println("\nAATree Operations\n");
//             System.out.println("1. insert ");
//             System.out.println("2. search");
//             System.out.println("3. count nodes");
//             System.out.println("4. check empty");
//             System.out.println("5. clear");

//             int choice = scan.nextInt();            
//             switch (choice)
//             {
//             case 1 : 
//                 System.out.println("Enter integer element to insert");
//                 aat.insert( scan.nextInt() );                     
//                 break;                          
//             case 2 : 
//                 System.out.println("Enter integer element to search");
//                 System.out.println("Search result : "+ aat.search( scan.nextInt() ));
//                 break;                                          
//             case 3 : 
//                 System.out.println("Nodes = "+ aat.countNodes());
//                 break;     
//             case 4 : 
//                 System.out.println("Empty status = "+ aat.isEmpty());
//                 break;
//             case 5 : 
//                 System.out.println("\nTree Cleared");
//                 aat.clear();
//                 break;            
//             default : 
//                 System.out.println("Wrong Entry \n ");
//                 break;   
//             }
//             /**  Display tree  **/ 
//             System.out.print("\nPost order : ");
//             aat.postorder();
//             System.out.print("\nPre order : "); 
//             aat.preorder();
//             System.out.print("\nIn order : ");
//             aat.inorder();

//             System.out.println("\nDo you want to continue (Type y or n) \n");
//             ch = scan.next().charAt(0);                        
//         } while (ch == 'Y'|| ch == 'y');               
//     }
// }