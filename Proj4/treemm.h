#ifndef TREEMULTIMAP_INCLUDED
#define TREEMULTIMAP_INCLUDED

template <typename KeyType, typename ValueType>
class TreeMultimap
{
  private:
    struct Node{
        KeyType mKey;
        std::vector<ValueType> values;
        Node* left = nullptr;
        Node* right = nullptr;
    };
  
    Node* root;
  
    //Recursively delete each node
    void deleteNode(Node* aNode){
        if(aNode==nullptr) return;
        deleteNode(aNode->left);
        deleteNode(aNode->right);
        delete aNode;
    }
  public:

    class Iterator
    {
      public:
        //Default constructor that creates invalid iterator
        Iterator(){
            vecPointer = nullptr;
        }
        
        Iterator(Node* aNode)
        {
            if(aNode==nullptr) vecPointer = nullptr;
            else{
                vecPointer = &(aNode->values);
                n=0;
            }
        }

        ValueType& get_value() const
        {
            if(is_valid()){
                return (*(vecPointer))[n];
            }
            //If iterator isn't valid, throw error
            throw 1;
        }

        bool is_valid() const
        {
            //Invalid iterator if it doesn't point to anything, or if it is past last element of array
            if(vecPointer==nullptr || n>=vecPointer->size()) return false;
            return true;
        }

        void advance()
        {
            n++;
        }

      private:
        std::vector<ValueType>* vecPointer; //Pointer to vector of values
        int n; //Tracks which element of vector iterator is pointing to
    };

    TreeMultimap()
    {
        root = nullptr;
    }

    ~TreeMultimap()
    {
        deleteNode(root);
    }

    void insert(const KeyType& key, const ValueType& value)
    {
        Node* newNode = new Node;
        newNode->mKey = key;
        ValueType val = value;
        newNode->values.push_back(val);
        newNode->left = nullptr;
        newNode->right = nullptr;
        //Creates root for bst if tree is empty
        if(root==nullptr){
            root = newNode;
        }
        else{
            //Go down bst to find where to insert key/value. If a key already exists, add value to key
            for(Node* p = root;;){
                //Check right node
                if(key > p->mKey){
                    //If right node is empty, then add new node with key/value
                    if(p->right==nullptr){
                        p->right = newNode;
                        break;
                    }
                    else p=p->right;
                }
                //Check left node
                else if(key < p->mKey){
                    //If left node is empty, then add new node with key/value
                    if(p->left==nullptr){
                        p->left = newNode;
                        break;
                    }
                    else p=p->left;
                }
                //Add value to key if key already exists
                else{
                    ValueType val = value;
                    p->values.push_back(val);
                    delete newNode;
                    break;
                }
            }
        }
    }

    Iterator find(const KeyType& key) const
    {
        for(Node* p = root;;){
            //Check right node
            if(key > p->mKey){
                //If right node is empty, return invalid iterator
                if(p->right==nullptr){
                    Iterator it;
                    return it;
                }
                //Otherwise take right node and check again
                else p=p->right;
            }
            //Check left node
            else if(key < p->mKey){
                //If left node is empty, return invalid iterator
                if(p->left==nullptr){
                    Iterator it;
                    return it;                }
                //Otherwise take left node and check again
                else p=p->left;
            }
            //If key is found, return an iterator pointing to that key's values vector
            else{
                Iterator it(p);
                return it;
            }
        }
    }


    
};

#endif // TREEMULTIMAP_INCLUDED
