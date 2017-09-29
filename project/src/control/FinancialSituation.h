//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_FINANCIAL_SITUATION_H
#define PROJECT_FINANCIAL_SITUATION_H

#include <list>

namespace project {

class FinancialSituation {
public:
    ReportManager();
    ~ReportManager();
    
private:
    list<Release*> releases;

};
    
}  // namespace project

#endif
