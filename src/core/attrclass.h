#pragma once
#include <vector>


class attribute{
    private:
        int key;
        int value;
        bool isdefault;
        bool isstatic;
    public:
        attribute(int __key, int __value, bool isdefault = false, bool isstatic = false);
        void Set(int __value);
        int Get();
        int GetKey();
};

class attrClass{
    private:
        std::vector<attribute> attributes;
    public:
        void NewAttr(int __key, int __value);
        void SetAttr(int __key, int __value);
        int GetAttr(int __key);
        void RemAttr(int __key);
};