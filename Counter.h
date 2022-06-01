#ifndef COUNTER_H
#define COUNTER_H
#include <wx/wx.h>

class Count{
    int num;

    public:
    Count();
    void up();
    void down();
    int getCount();
    void reset();
};

class MainFrame : public wxFrame{
    public:
    MainFrame();

    private:
    wxStaticText* out = nullptr;
    wxButton* up_btn = nullptr;
    wxButton* reset_btn = nullptr;
    wxButton* down_btn = nullptr;
    Count* count = nullptr;
    std::string num = "    1";
    void up(wxCommandEvent &evt);
    void down(wxCommandEvent &evt);
    void reset(wxCommandEvent &evt);

    wxDECLARE_EVENT_TABLE();
};

class counter : public wxApp{
    MainFrame* main = nullptr;
    virtual bool OnInit();
};

#endif
