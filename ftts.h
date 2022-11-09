/*class Word {
    public:
        int *occurrence;
        char *word;
}
*/
template <typename T>
class FTTS
{
    private:
        ArraySequence<LinkedListSequence<int>> *table;
        int size;
        int k;
    public:
        FTTS(int count) {
            size = count;

        }
        long long Hash(char *str);
        void AddWord(char *str);
        Word GetIndex(int ind);
        Word Get(char *str);
};
