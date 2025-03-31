#include <vector>

class Interpolation {
public:
    Interpolation() = default;

    
    static std::vector<double> interpolate_1d(const std::vector<double>& x,
        const std::vector<double>& y,
        const std::vector<double>& x_interp);

    
    static std::vector<double> interpolate_2d(const std::vector<double>& x,
        const std::vector<double>& y,
        const std::vector<std::vector<double>>& z,
        const std::vector<double>& x_interp,
        const std::vector<double>& y_interp);
};

std::vector<double> Interpolation::interpolate_1d(const std::vector<double>& x,
    const std::vector<double>& y,
    const std::vector<double>& x_interp) {
    std::vector<double> y_interp;
    for (double xi : x_interp) {
        for (size_t i = 0; i < x.size() - 1; ++i) {
            if (x[i] <= xi && xi <= x[i + 1]) {
                double yi = y[i] + (y[i + 1] - y[i]) * (xi - x[i]) / (x[i + 1] - x[i]);
                y_interp.push_back(yi);
                break;
            }
        }
    }
    return y_interp;
}

std::vector<double> Interpolation::interpolate_2d(const std::vector<double>& x,
    const std::vector<double>& y,
    const std::vector<std::vector<double>>& z,
    const std::vector<double>& x_interp,
    const std::vector<double>& y_interp) {
    std::vector<double> z_interp;
    for (size_t k = 0; k < x_interp.size(); ++k) {
        double xi = x_interp[k];
        double yi = y_interp[k];
        for (size_t i = 0; i < x.size() - 1; ++i) {
            if (x[i] <= xi && xi <= x[i + 1]) {
                for (size_t j = 0; j < y.size() - 1; ++j) {
                    if (y[j] <= yi && yi <= y[j + 1]) {
                        double z00 = z[i][j];
                        double z01 = z[i][j + 1];
                        double z10 = z[i + 1][j];
                        double z11 = z[i + 1][j + 1];
                        double zi = (z00 * (x[i + 1] - xi) * (y[j + 1] - yi) +
                            z10 * (xi - x[i]) * (y[j + 1] - yi) +
                            z01 * (x[i + 1] - xi) * (yi - y[j]) +
                            z11 * (xi - x[i]) * (yi - y[j])) / ((x[i + 1] - x[i]) * (y[j + 1] - y[j]));
                        z_interp.push_back(zi);
                        break;
                    }
                }
                break;
            }
        }
    }
    return z_interp;
}
