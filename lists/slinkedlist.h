#ifndef S_LINKED_LIST_H_
#define S_LINKED_LIST_H_

#ifndef NULL
#define NULL 0
#endif // NULL

template<typename T>
struct Node
{
	T data;

	Node* next;
};


template<typename T>
class SLinkedList
{
public:
	/* interface:
	
		SLinkedList();
		SLinkedList(const SLinkedList<T>& l);
		SLinkedList<T>& operator = (const SLinkedList<T>& l);
		virtual ~SLinkedList();
		void clear();
		bool empty() const;
		T* front() const;
		T* back() const;
		void push_front(const T& elem);
		void pop_front();
		void insert_after(const T& elem, const T& new_elem);
		void erase(const T& elem);
		void push_back(const T& elem);
		void erase_back();

	*/

	SLinkedList()
	: head_(NULL),
	  tail_(NULL),
	  size_(0)
	{
	}

	SLinkedList(const SLinkedList<T>& l)
	: head_(NULL),
	  tail_(NULL),
	  size_(0)
	{
		copy_data(l);

		this->size_ = l.size_;
	}

	SLinkedList<T>& operator = (const SLinkedList<T>& l)
	{
		if(this != &l)
		{
			copy_data(l);
			this->size_ = l.size_;
		}

		return *this;
	}

	virtual ~SLinkedList()
	{
		clear();
	}

	// erase all elements
	void clear()
	{
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

		++this->size_;
	}

	void pop_front()
	{
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

		this->tail_->next = new_node;

		++this->size_;
	}

	// 0(n) because is single linked
	void erase_back()
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
	void copy_data(const SLinkedList<T>& r_list)
	{
		// Copy first elem
		this->head_ = new Node<T>();
		this->head_->data = r_list.head_->data;

		// loop the list because we have only one element
		this->head_->next = this->tail_;
		this->tail_->next = this->head_;

		// Start with second element
		Node<T>* it = r_list.head_->next;

		while(it != NULL)
		{
			Node<T>* new_elem = new Node<T>();
			new_elem->data = it->data;
			new_elem->next = it->next;

			this->tail_->next = new_elem;
		}
	}

	Node<T>* head_;
	Node<T>* tail_;
	int size_;
};


#endif // S_LINKED_LIST_H_
