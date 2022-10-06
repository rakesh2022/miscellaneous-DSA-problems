/*
    link: https://www.geeksforgeeks.org/count-balanced-binary-trees-height-h/

    all solution in link.

    logic:
    here as per 3 condition

                root
                /   \
    left sub tree    right sub tree
    (h-2)            (h-1)
    (h-1)            (h-2)
    (h-1)            (h-1)

    so
   count(h) = count(h-1) * count(h-2) + count(h-2) * count(h-1) + count(h-1) * count(h-1)
            = 2 * count(h-1) * count(h-2) + count(h-1) * count(h-1)
            = count(h-1) * (2*count(h - 2) + count(h - 1))

    why multiply?
    bcoz for each sub tree with (h-2) it can be pair with all different (h-1) and vice-verca.

    why vice-verca ?
    bcoz it will be counted as unique if
    (h-2) height trees on left side and (h-1) on right side
    (h-1) height trees on left side and (h-2) on right side
*/

// ----------------------------------------------------------------------------------------------------------------------- //

// C++ program to count number of balanced
// binary trees of height h.
class Solution
{
public:
    long long m = 1e9 + 7;
    long long mul(long long a, long long b)
    {
        return (a * b) % m;
    }
    long long int countBT(int h)
    {
        long long t[h + 1];
        t[0] = 1;
        t[1] = 1;
        t[2] = 3;
        for (int i = 3; i <= h; i++)
        {
            long long a = mul(t[i - 1], t[i - 1]);
            long long b = mul(t[i - 1], t[i - 2]);
            b = mul(2, b);
            t[i] = (a + b) % m;
        }
        return t[h];
    }

    // ----------------------------------------------------------------------------------------------------------------------- //