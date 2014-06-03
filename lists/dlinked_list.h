#ifndef D_LINKED_LIST_H_
#define D_LINKED_LIST_H_


template<typename T>
struct Node
{
    T data;
    Node<T>* prev;
    Node<T>* next;
}

template<typename T>
class DLinkedList
{
public:
	/* interface:
	
		DLinkedList();
		DLinkedList(const DLinkedList<T>& l);
		DLinkedList<T>& operator = (const DLinkedList<T>& l);
		virtual ~DLinkedList();
		void clear();
		bool empty() const;
		Node<T>* begin_iterator();
		Node<T>* reverse_iterator();
		T* front() const;
		T* back() const;
		void push_front(const T& elem);
		void pop_front();
		void insert_after(const T& elem, const T& new_elem);
		void erase(const T& elem);
		void push_back(const T& elem);
		void pop_back();

	*/

	DLinkedList()
	: head_(NULL),
	  tail_(NULL),
	  size_(0)
	{
	}

	DLinkedList(const DLinkedList<T>& l)
	: head_(NULL),
	  tail_(NULL),
	  size_(0)
	{
		copy_data(l);

		this->size_ = l.size_;
	}

	DLinkedList<T>& operator = (const DLinkedList<T>& l)
	{
		if(this != &l)
		{
			this->clear();
			copy_data(l);
			this->size_ = l.size_;
		}

		return *this;
	}

    Node<T>* begin_iterator() const
    {
        return this->head_;
    }

	const Node<T>* cbegin_iterator() const
	{
	    return this->head_;
	}
	
	
	virtual ~DLinkedList()
	{
		clear();
	}

	// erase all elements
	void clear()
	{
	    if(this->empty())
	    {
	        return;
	    }
		
		Node<T>* it = NULL;

		while(this->head_ != NULL)
		{
			it = this->head_;
			this->head_ = this->head_->next;
			delete it;
			--this->size_;
		}
	}

	// check if the list is empty
	bool empty() const
	{
		return this->size_ == 0;
	}

	int size() const
	{
		return this->size_;
	}

	// return NULL if the list is empty
	T* front() const
	{
		return &this->head_->data;
	}

	T* back() const
	{
		return &this->tail_->data;
	}

	void push_front(const T& elem)
	{
		Node<T>* new_elem = new Node<T>();
		
		new_elem->data = elem;
		new_elem->next = this->head_;
		
		// move the head
		this->head_ = new_elem;
        
        
        if(!this->tail_)
        {
            // this happens only
            // when we push first element
            this->tail_ = this->head_; 
        }
		
		++this->size_;
	}

	void pop_front()
	{
		if(this->empty())
		{
		    return;
		}

		Node<T>* to_remote = this->head_;
		this->head_ = this->head_->next;

		delete to_remote;
		--this->size_;
	}

	void insert_after(const T& elem, const T& new_elem)
	{
		Node<T>* it = this->head_;
		while(it != NULL)
		{
			if(it->data == elem)
			{
				break;
			}
			
			it = it->next;
		}

		if(it == NULL)
		{
			// throw "first argument is not in the list"
			return;
		}

		Node<T>* new_node = new Node<T>();
		new_node->data = new_elem;
		new_node->next = it->next;
		it->next = new_node;

		++this->size_;
	}

	void erase(const T& elem)
	{
	    if(this->empty())
	    {
	        return;
	    }

		Node<T>* it = this->head_;
		Node<T>* prev = it;

		while(it)
		{
			if(it->data == elem)
			{
				break;
			}
			else
			{
				prev = it;
				it = it->next;
			}
		}

		if(it != NULL)
		{
			prev->next = it->next;

			delete it;
		}

		--this->size_;
	}

	void push_back(const T& elem)
	{
	    Node<T>* new_node = new Node<T>();
	    new_node->data = elem;
	    new_node->next = NULL;

	    if(!this->tail_)
	    {
	        this->tail_ = new_node;
	    }
	    else
	    {
	        this->tail_->next = new_node;
            this->tail_ = new_node;
        }

        if(!this->head_)
        {
            // this happens only on
            // first push
            this->head_ = this->tail_;
        }

		++this->size_;
	}

	// 0(n) because is single linked
	void pop_back()
	{
		// find the previous than this->tail
		Node<T>* it = this->head_;
		while(it->next != this->tail_)
		{
			it = it->next;
		}

		// get handle to tail_
		Node<T>* for_delete = this->tail_;
		
		// delete the tail
		delete for_delete;

		// set tail_ to point to its previous elem
		this->tail_ = it;
		this->tail_->next = NULL;
	
		--this->size_;
	}
private:
    Node<T>* head_;
    Node<T>* tail_;
};
#endif // D_LINKED_LIST_H_
