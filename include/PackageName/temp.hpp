#ifndef PACKAGENAME_TEMP_HPP
#define PACKAGENAME_TEMP_HPP

class Temp
{
  public:
    // constructor
    explicit Temp(int pVar);

    void print();

    // member variables
    int mVar;

  private:
    // class variables
    static const int C_COUNT;
};

#endif// PACKAGENAME_TEMP_HPP
