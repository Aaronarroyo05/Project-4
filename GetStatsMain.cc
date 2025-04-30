int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "ERROR: Please specify a file name at the command line." << endl;
        return 1;
    }

    try {
        string filename(argv[1]);
        StatCalculator calculator(filename);

        cout << "n:      " << calculator.GetSampleSize() << endl;
        cout << "Mean:   " << setprecision(4) << calculator.EstimateMean() << endl;

        try {
            cout << "StdDev: " << setprecision(4) << calculator.EstimateStandardDeviation() << endl;
        } catch (const exception &e) {
            cerr << e.what() << endl;
        }

        cout << "Max:    " << setprecision(4) << calculator.FindMax() << endl;
        cout << "Min:    " << setprecision(4) << calculator.FindMin() << endl;

    } catch (const exception &e) {
        cerr << e.what() << endl;
        return 2;
    }

    return 0;
}
