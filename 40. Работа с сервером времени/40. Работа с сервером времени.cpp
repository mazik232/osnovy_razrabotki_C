#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    int x = 1;
    string a = "05:05:05";
    if (x == 0) {
        throw runtime_error("Time server is not responding");
    }
    else if (x == 1) {
        return a;
    }
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            string new_time = AskTimeServer(); // Получаем время от сервера
            last_fetched_time = new_time; // Обновляем значение поля
        }
        catch (system_error&) {
            // Если произошла ошибка системного характера, сохраняем текущее время
        }
        // Возвращаем значение поля - либо новое, либо старое
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
