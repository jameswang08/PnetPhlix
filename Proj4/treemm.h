#ifndef TREEMULTIMAP_INCLUDED
#define TREEMULTIMAP_INCLUDED

template <typename KeyType, typename ValueType>
class TreeMultimap
{
  public:
    class Iterator
    {
      public:
        Iterator()
        {
            // Replace this line with correct code.
        }

        ValueType& get_value() const
        {
            throw 1;  // Replace this line with correct code.
        }

        bool is_valid() const
        {
            return false;  // Replace this line with correct code.
        }

        void advance()
        {
            // Replace this line with correct code.
        }

      private:
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
        return Iterator();  // Replace this line with correct code.
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
