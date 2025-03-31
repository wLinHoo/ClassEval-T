
#include <algorithm> 
#include <sstream>   

#include <string>

class NumberWordFormatter {
public:
    NumberWordFormatter();

    std::string format(int x);
    std::string format(double x);
    std::string format(const std::string& x);
    std::string format(std::nullptr_t);
    std::string trans_two(const std::string& s);
    std::string trans_three(const std::string& s);
    std::string parse_more(int i);

private:
    const std::string NUMBER[10];
    const std::string NUMBER_TEEN[10];
    const std::string NUMBER_TEN[9];
    const std::string NUMBER_MORE[4];
    const std::string NUMBER_SUFFIX[20];
};


NumberWordFormatter::NumberWordFormatter()
    : NUMBER{ "", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" },
    NUMBER_TEEN{ "TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN" },
    NUMBER_TEN{ "TEN", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY" },
    NUMBER_MORE{ "", "THOUSAND", "MILLION", "BILLION" },
    NUMBER_SUFFIX{ "k", "w", "", "m", "", "", "b", "", "", "t", "", "", "p", "", "", "e" } {}

std::string NumberWordFormatter::format(int x) {
    std::stringstream ss;
    ss << x;
    return format(ss.str());
}

std::string NumberWordFormatter::format(double x) {
    std::stringstream ss;
    ss << x;
    return format(ss.str());
}

std::string NumberWordFormatter::format(const std::string& x) {
    std::string lstr = x.substr(0, x.find('.'));
    std::string rstr;
    auto now = x.find('.');
    if (x.find('.') != std::string::npos)
    {
        rstr = x.substr(x.find('.') + 1);
    }
    std::reverse(lstr.begin(), lstr.end());

    if (lstr.size() % 3 == 1) lstr += "00";
    else if (lstr.size() % 3 == 2) lstr += "0";

    std::string a[5] = { "", "", "", "", "" };
    std::string lm = "";

    for (size_t i = 0; i < lstr.size() / 3; ++i) {
        a[i] = std::string(1, lstr[3 * i + 2]) + std::string(1, lstr[3 * i + 1]) + std::string(1, lstr[3 * i]);
        
        if (a[i] != "000") {
            lm = trans_three(a[i]) + " " + parse_more(i) + " " + lm;
        }
        else {
            lm += trans_three(a[i]);
        }
    }
    std::string xs = !rstr.empty() ? "AND CENTS " + trans_two(rstr) + " " : "";
    if (lm.empty()) {
        return "ZERO ONLY";
    }
    else {
        int nowpos = 0;
        for (int i = lm.size() - 1; i >= 0; --i)
        {
            if (lm[i] != ' ')
            {
                nowpos = i;
                break;
            }
        }
        lm = lm.substr(0, nowpos + 1);
        return lm + " " + xs + "ONLY";
    }
}

std::string NumberWordFormatter::format(std::nullptr_t) {
    return "";
}

std::string NumberWordFormatter::trans_two(const std::string& s) {
    std::string ss = s;
    if (ss.size() == 1) ss = "0" + ss;

    if (ss[0] == '0') {
        return NUMBER[ss[1] - '0'];
    }
    else if (ss[0] == '1') {
        return NUMBER_TEEN[std::stoi(ss) - 10];
    }
    else if (ss[1] == '0') {
        return NUMBER_TEN[ss[0] - '1'];
    }
    else {
        return NUMBER_TEN[ss[0] - '1'] + " " + NUMBER[ss[1] - '0'];
    }
}

std::string NumberWordFormatter::trans_three(const std::string& s) {
    if (s[0] == '0') {
        return trans_two(s.substr(1));
    }
    else if (s.substr(1) == "00") {
        return NUMBER[s[0] - '0'] + " HUNDRED";
    }
    else {
        return NUMBER[s[0] - '0'] + " HUNDRED AND " + trans_two(s.substr(1));
    }
}

std::string NumberWordFormatter::parse_more(int i) {
    return NUMBER_MORE[i];
}
