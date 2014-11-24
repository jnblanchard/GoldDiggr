#import "SChartPointStruct.h"
#import "SChartSeriesDataBin.h"
@class SChartMappedSeries;

typedef struct SChartSeriesDistanceInfo
{
    double distance;
    SChartInternalDataPoint *__unsafe_unretained point;
    SChartSeriesDataBin *__unsafe_unretained bin;
    SChartMappedSeries *__unsafe_unretained series;
    SChartPoint resolvedPoint;
} SChartSeriesDistanceInfo;
