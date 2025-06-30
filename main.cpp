#include "orderedlist.h"
#include "test.h"

void testEmptyAfterAddRemove();
void testContainsItemsInOrder();
void testContainsCorrectItemsAfterRemove();

int main(int argc, char const *argv[])
{
    testEmptyAfterAddRemove();
    testContainsItemsInOrder();
    return 0;
}

void testEmptyAfterAddRemove()
{
    try{
    OrderedList<int> word;
    word.add(4);
    word.remove(4);
    throw word.empty();
    }
    catch (bool e) {
        testTrue(e, "empty on add remove");
    };
}

void testContainsItemsInOrder()
{
try
{
    OrderedList<double> doubles;
    doubles.add(4.123);
    doubles.add(3452.1);
    doubles.add(-2349);
    doubles.add(101.4);
    doubles.add(0.011);
    doubles.add(32);
    doubles.add(91);
    doubles.add(-1);
    throw doubles.toVector();
}
catch(const std::vector<double>& e)
{
    testTrue(e[0] == -2349, "Vector returned is in order\n");
}
}

void testContainsCorrectItemsAfterRemove()
{

}
