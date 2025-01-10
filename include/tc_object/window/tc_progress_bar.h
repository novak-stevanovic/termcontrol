#ifndef TC_PROGRESS_BAR_H
#define TC_PROGRESS_BAR_H

#include "tc_window.h"

typedef struct TCProgressBar
{
    struct TCWindow _base;
    double _progress;
} TCProgressBar;

void tc_progress_bar_init(TCProgressBar* progress_bar);

void tc_progress_bar_set_progress(TCProgressBar* progress_bar, double percentage);
double tc_progress_bar_get_progress(TCProgressBar* progress_bar);

#endif
