#ifndef RunningSample_h
#define RunningSample_h

class RunningSample
{
  private:
    int count;        /*the number of values in the array*/
    int size;         /*the size of the array*/
    int index;        /*where in the array we currently are*/
    double sum;       /*the sum of the values in the array. used to calucate the mean */
    double mean;      /*the arithmetic mean of the values in the array*/
    float* values;    /*the array*/

    float addValue( float );              /*add a value to the array. returns the old value that was there*/
    void calcAverage( float, float );     /*calculate the average of the values*/
    void averageWithSum( float);          /*called by calcAverage to calculate the mean* when the array isn't yet full */
    void runningAverage( float, float);   /*used by calcAverage when the array is full*/
  public:
    RunningSample( int );
    ~RunningSample();

    void addSample( float );
    double getAverage();
};

#endif
