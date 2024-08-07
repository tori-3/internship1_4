# pragma once

template<typename DataType>
List<DataType>::ConstIterator::ConstIterator(List<DataType>::Node* ptr, const List<DataType>* parent)
    :m_element{ ptr }
, m_parent{ parent }{};

template<typename DataType>
List<DataType>::ConstIterator::ConstIterator(const List<DataType>::ConstIterator& iterator)
    :m_element{ iterator.m_element }
    , m_parent{ iterator.m_parent } {}


template<typename DataType>
typename List<DataType>::ConstIterator List<DataType>::ConstIterator:: operator =(const List<DataType>::ConstIterator& iterator)
{
    m_element = iterator.m_element;
    m_parent = iterator.m_parent;
    return  *this;
}


template<typename DataType>
const DataType& List<DataType>::ConstIterator::operator *()const
{

    assert(m_element != nullptr);

    assert(m_element != m_parent->m_sentinel);

    return m_element->data;
}


template<typename DataType>
typename List<DataType>::ConstIterator& List<DataType>::ConstIterator::operator --()
{
    assert(m_element != nullptr);

    assert(m_element != m_parent->m_sentinel->back);

    m_element = m_element->front;
    return *this;
}


template<typename DataType>
typename List<DataType>::ConstIterator& List<DataType>::ConstIterator::operator ++()
{
    assert(m_element != nullptr);

    assert(m_element != m_parent->m_sentinel);

    m_element = m_element->back;
    return *this;
}


template<typename DataType>
typename List<DataType>::ConstIterator List<DataType>::ConstIterator::operator --(int)
{
    assert(m_element != nullptr);

    assert(m_element != m_parent->m_sentinel->back);

    auto old = *this;
    m_element = m_element->front;
    return old;
}

template<typename DataType>
typename List<DataType>::ConstIterator List<DataType>::ConstIterator::operator ++(int)
{
    assert(m_element != nullptr);

    assert(m_element != m_parent->m_sentinel);

    auto old = *this;
    m_element = m_element->back;
    return old;
}

template<typename DataType>
bool List<DataType>::ConstIterator::operator !=(ConstIterator right)const
{
    return m_element != right.m_element;
}

template<typename DataType>
bool List<DataType>::ConstIterator::operator ==(ConstIterator right)const
{
    return m_element == right.m_element;
}

//Iterator‚ÌŽÀ‘•
template<typename DataType>
DataType& List<DataType>::Iterator::operator *()
{
    assert(ConstIterator::m_element != nullptr);

    assert(ConstIterator::m_element != ConstIterator::m_parent->m_sentinel);

    return ConstIterator::m_element->data;
}



//List‚ÌŽÀ‘•

template<typename DataType>
List<DataType>::List() :m_sentinel{ new Node{} }
{
    m_sentinel->back = m_sentinel;
    m_sentinel->front = m_sentinel;
}

template<typename DataType>
List<DataType>::~List()
{
    Node* node = m_sentinel->back;

    while (node != m_sentinel)
    {
        auto temp = node->back;
        delete node;
        node = temp;
    }

    delete m_sentinel;
}

template<typename DataType>
typename List<DataType>::Iterator List<DataType>::begin()
{
    return Iterator{ m_sentinel->back,this };
}

template<typename DataType>
typename List<DataType>::Iterator List<DataType>::end()
{
    return Iterator{ m_sentinel,this };
}

template<typename DataType>
typename List<DataType>::ConstIterator List<DataType>::begin() const
{
    return ConstIterator{ m_sentinel->back, this };
}

template<typename DataType>
typename List<DataType>::ConstIterator List<DataType>::end() const
{
    return ConstIterator{ m_sentinel,this };
}

template<typename DataType>
typename List<DataType>::ConstIterator List<DataType>::constBegin() const
{
    return ConstIterator{ m_sentinel->back,this };
}

template<typename DataType>
typename List<DataType>::ConstIterator List<DataType>::constEnd() const
{
    return ConstIterator{ m_sentinel,this };
}

template<typename DataType>
size_t List<DataType>::size()const
{
    return m_size;
}

template<typename DataType>
bool List<DataType>::insert(List<DataType>::ConstIterator iterator, const DataType& addData)
{
    Node* node = iterator.m_element;

    if (node == nullptr || iterator.m_parent != this)
    {
        return false;
    }

    Node* addNode = new Node{ addData };
    Node* frontNode = node->front;

    node->front = addNode;
    addNode->back = node;

    addNode->front = frontNode;
    frontNode->back = addNode;

    ++m_size;

    return true;
}

template<typename DataType>
bool List<DataType>::remove(List<DataType>::ConstIterator iterator)
{

    Node* node = iterator.m_element;

    if (node == nullptr || iterator.m_parent != this || iterator == constEnd())
    {
        return false;
    };

    node->front->back = node->back;
    node->back->front = node->front;
    delete node;

    --m_size;

    return true;
}

template<typename DataType>
void List<DataType>::add(const DataType& addData)
{
    insert(end(), addData);
}

template<typename DataType>
void List<DataType>::sort(std::function<bool(const DataType&, const DataType&)>compare)
{
    if (m_size <= 1 || compare==nullptr)
    {
        return;
    }

    auto ans=quickSort(m_sentinel->back, m_sentinel->front, compare);

    m_sentinel->back = ans.first;
    ans.first->front = m_sentinel;

    ans.second->back = m_sentinel;
    m_sentinel->front = ans.second;
}


template<typename DataType>
std::pair<typename List<DataType>::Node*, typename List<DataType>::Node*> List<DataType>::quickSort(List<DataType>::Node* leftNode, List<DataType>::Node* rightNode, std::function<bool(const DataType&, const DataType&)>compare)
{
    if (leftNode == rightNode)
    {
        return { leftNode,rightNode };
    }

    DataType pivot = leftNode->data;

    Node* resultLeft = leftNode;
    Node* resultRight = leftNode;

    Node sentinelLeft;
    Node sentinelRight;

    Node* left = &sentinelLeft;
    Node* right = &sentinelRight;

    rightNode->back = nullptr;
    for (Node* node = leftNode->back; node ; node = node->back)
    {
        if (compare(node->data , pivot))
        {
            left->back = node;
            node->front = left;
            left = node;
        }
        else
        {
            right->back = node;
            node->front = node;
            right = node;
        }
    }

    if(sentinelLeft.back)
    {
        auto result = quickSort(sentinelLeft.back, left, compare);
        resultLeft = result.first;
        result.second->back=resultRight;
        resultRight->front = result.second;
    }

    if (sentinelRight.back)
    {
        auto result = quickSort(sentinelRight.back, right, compare);
        resultRight->back = result.first;
        result.first->front= resultRight;
        resultRight = result.second;
    }

    return { resultLeft,resultRight };
}
