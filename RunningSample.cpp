#include <Arduino.h>
#include "RunningSample.h"

RunningSample::RunningSample( int arrLen )
{
  values = (float*)calloc(sizeof(float), arrLen);
  /*fixme: add error handling */

  count = 0;
  index = 0;
  size  = arrLen;
  sum   = 0.0;
  mean  = 0.0;

}

RunningSample::~RunningSample()
{
  delete values;

}

float RunningSample::addValue( float aValue )
{
  float returnme;
  returnme = values[index];
  values[index] = aValue;
  index = (index + 1) % size;

  if (count <= size) 
    count++;

  return returnme;
}

void RunningSample::calcAverage( float oldValue, float newValue )
{
  if( count <= size )
    averageWithSum( newValue );
  else
    runningAverage( oldValue, newValue );

}

void RunningSample::averageWithSum( float newValue )
{
  sum += newValue;
  mean = sum / count;
}

void RunningSample::runningAverage( float oldValue, float newValue )
{
  mean = mean + (newValue - oldValue) / size;

}


void RunningSample::addSample( float newValue )
{
  float oldValue;

  oldValue = addValue( newValue );
  calcAverage( oldValue, newValue );


}

double RunningSample::getAverage()
{
  return mean;

}

