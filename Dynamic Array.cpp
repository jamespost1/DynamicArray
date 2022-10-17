#include <iostream>
using namespace std;

class DynamicArray
{
    private:
        string* dynamicArray;
        int size;

    public:
        DynamicArray()
        {
            dynamicArray = NULL;
            size = 0;
        }

        int length() const
        {
            return size;
        }

        void addEntry(const string& elem)
        {
            string* temp = new string[size + 1];

            for (int i = 0; i < size; i++)
            {
                temp[i] = dynamicArray[i];
            }

            temp[size] = elem;
            size++;

            if (dynamicArray != NULL)
                delete [] dynamicArray;
            
            dynamicArray = temp;
        }

        bool deleteEntry(const string& value)
        {
            bool exist = false;
            int index;
            for (int i = 0; i < size; i++)
            {
                if (value == dynamicArray[i])
                {
                    index = i;
                    exist = true;
                    break;
                }
            }
            if (exist)
            {
                string * tmp = new string[--size];
                for (int i = 0; i < index; i++)
                {
                    tmp[i] = dynamicArray[i];
                }
                for (int i = index; i < size; i++)
                {
                    tmp[i] = dynamicArray[i + 1];
                }

                delete [] dynamicArray;
                dynamicArray = tmp;
                
                return true;

            }
            cout << "Value "<< value << ": does not exist in dynamicArray" << endl;
            return false;

        }

        }

        string getEntry(const int& index) const
        {
            if (index >= size)
            {
                cout << "Index: " << index << ": out of bounds" << endl;
                exit(1);
            }
            return dynamicArray[index];
        }  

        DynamicArray(const DynamicArray<string>& other): size(other.size)
        {
            if (size > 0)
            {
                dynamicArray = new string[size];
                for (int i = 0; i < size; i++)
                {
                    dynamicArray[i] = other.dynamicArray[i];
                }
            }
        }

        DynamicArray<string> operator = (const DynamicArray<string>& other)
        {
            if (this != &other)
            {
                if (dynamicArray != NULL)
                {
                    delete [] dynamicArray;
                }

                size = other.size;
                if (size > 0)
                {
                    dynamicArray = new string[size];   
                }

                for (int i = 0; i < size; i++)
                {
                    dynamicArray[i] = other.dynamicArray[i];
                }
            }
            return *this;                
        }

        ~DynamicArray()
        {
            if (dynamicArray != NULL)
            {
                delete [] dynamicArray;
                dynamicArray = NULL;
            }
        }
};