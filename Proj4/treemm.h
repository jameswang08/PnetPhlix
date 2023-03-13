#ifndef TREEMULTIMAP_INCLUDED
#define TREEMULTIMAP_INCLUDED

template <typename KeyType, typename ValueType>
class TreeMultimap
{
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
            if(is_valid){
                ValueType val = vecPointer[n];
                return val;
            }
            //Won't do anything if iterator is invalid
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
        newNode->nKey = key;
        ValueType val = value;
        newNode->values.insert(val);
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
                if(key > p->nKey){
                    //If right node is empty, then add new node with key/value
                    if(p->right==nullptr){
                        p->right = newNode;
                        break;
                    }
                    else p=p->right;
                }
                //Check left node
                else if(key < p->nKey){
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
            if(key > p->nKey){
                //If right node is empty, return invalid iterator
                if(p->right==nullptr){
                    return TreeMultimap<KeyType,ValueType>::Iterator it;
                }
                //Otherwise take right node and check again
                else p=p->right;
            }
            //Check left node
            else if(key < p->nKey){
                //If left node is empty, return invalid iterator
                if(p->left==nullptr){
                    return TreeMultimap<KeyType,ValueType>::Iterator it;
                }
                //Otherwise take left node and check again
                else p=p->left;
            }
            //If key is found, return an iterator pointing to that key's values vector
            else{
                return TreeMultimap<KeyType,ValueType>::Iterator it(p);
            }
        }
    }

  private:
    struct Node{
        KeyType nKey;
        std::vector<ValueType> values;
        Node* left;
        Node* right;
    };
    
    Node* root;
    
    //Recursively delete each node
    void deleteNode(Node* aNode){
        if(aNode->left != nullptr) deleteNode(aNode->left);
        if(aNode->right != nullptr) deleteNode(aNode->left);
        delete aNode;
    }
    
};

#endif // TREEMULTIMAP_INCLUDED
