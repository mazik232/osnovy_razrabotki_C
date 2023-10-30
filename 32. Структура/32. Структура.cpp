#include <iostream>

using namespace std;

struct Specialization {
    string word;
    explicit Specialization(string new_word) {
        word = new_word;
    }
};
struct Course {
    string word;
    explicit Course(string new_word) {
        word = new_word;
    }
};

struct Week {
    string word;
    explicit Week(string new_word) {
        word = new_word;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization new_specialization, Course new_course, Week new_week) {
        specialization = new_specialization.word;
        course = new_course.word;
        week = new_week.word;
    }
};

void PrintLecture(const LectureTitle& a) {
    cout << a.specialization << " " << a.course << " " << a.week << endl;
}



int main()
{
    LectureTitle title(Specialization("C++"), Course("White belt"), Week("4th"));
    PrintLecture(title);
    /*
    LectureTitle title("C++", "White belt", "4th");

    LectureTitle title(string("C++"), string("White belt"), string("4th"));

    LectureTitle title = { "C++", "White belt", "4th" };

    LectureTitle title = { {"C++"}, {"White belt"}, {"4th"} };

    LectureTitle title(
        Course("White belt"),
        Specialization("C++"),
        Week("4th")
    );

    LectureTitle title(
        Specialization("C++"),
        Week("4th"),
        Course("White belt")
    );
    */
}

