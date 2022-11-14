#ifndef F_LAB2_SEQ
#define F_LAB2_SEQ

template <typename T>
class Sequence {
    public:
        virtual T Get(int index) const = 0;
        virtual T &GetRef(int index) const = 0;

        virtual void Set(int index, T value) = 0;
        virtual Sequence<T> *GetSubSequence(int startIndex, int endIndex) const = 0;

        virtual T GetFirst() const = 0;
        virtual T GetLast() const = 0;
        virtual int GetLength() const = 0;
        //virtual int GetHeigth() const = 0;
        //virtual int GetWidth() const = 0;

        virtual void Append(const T& item) = 0;
        virtual void Prepend(T item) = 0;
        virtual void InsertAt(T item, int index) = 0;

        virtual Sequence<T> *Concat(Sequence<T> *list) = 0;
        virtual Sequence<T> *Copy() const = 0;
        
        virtual ~Sequence() {}
};

#endif
