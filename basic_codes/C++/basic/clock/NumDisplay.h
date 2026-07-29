#ifndef NUMDISPAY_H
    #define NUMDISPAY_H
    class NumDisplay{
    private:
        int val;
        int lim;
    public:
        int increase();
        int set_val(int origin);
        int set_lim(int limit);
    };
#endif