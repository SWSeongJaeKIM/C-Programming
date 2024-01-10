#include <iostream>
#include <cmath>

using namespace std;

float calculateInductiveReactance(float frequency, float inductance) {
    return 2 * M_PI * frequency * inductance;
}

float calculateCapacitiveReactance(float frequency, float capacitance) {
    return 1 / (2 * M_PI * frequency * capacitance);
}

float calculateImpedance(float resistance, float reactanceL, float reactanceC) {
    return sqrt((resistance * resistance) + ((reactanceL - reactanceC) * (reactanceL - reactanceC)));
}

float calculateMaxCurrent(float maxVoltage, float impedance) {
    return maxVoltage / impedance;
}

float calculatePhaseAngle(float resistance, float reactanceL, float reactanceC) {
    return atan((reactanceL - reactanceC) / resistance) * (180 / M_PI);
}

float calculateVoltageRMax(float maxCurrent, float resistance) {
    return maxCurrent * resistance;
}

float calculateVoltageLMax(float maxCurrent, float reactanceL) {
    return maxCurrent * reactanceL;
}

float calculateVoltageCMax(float maxCurrent, float reactanceC) {
    return maxCurrent * reactanceC;
}

int main() {
    float inductance, impedance, reactanceC, frequency, maxVoltage, maxCurrent, phaseAngle, voltageRMax, voltageLMax, voltageCMax = 0.0;
    float resistance, capacitance, reactanceL;

    inductance = 0.6;
    maxVoltage = 150;
    frequency = 60.0;

    cout << "Enter Resistance (Ohm): ";
    cin >> resistance;

    cout << "Enter Capacitance (Farad): ";
    cin >> capacitance;

    reactanceL = calculateInductiveReactance(frequency, inductance);
    reactanceC = calculateCapacitiveReactance(frequency, capacitance);
    impedance = calculateImpedance(resistance, reactanceL, reactanceC);
    maxCurrent = calculateMaxCurrent(maxVoltage, impedance);
    phaseAngle = calculatePhaseAngle(resistance, reactanceL, reactanceC);
    voltageRMax = calculateVoltageRMax(maxCurrent, resistance);
    voltageLMax = calculateVoltageLMax(maxCurrent, reactanceL);
    voltageCMax = calculateVoltageCMax(maxCurrent, reactanceC);

    cout << "Inductive Reactance (XL): " << reactanceL << " (Ohm)\n";
    cout << "Capacitive Reactance (XC): " << reactanceC << " (Ohm)\n";
    cout << "Maximum Current (Imax): " << maxCurrent << " (A)\n";
    cout << "Impedance (Z): " << impedance << " (Ohm)\n";
    cout << "Phase Angle (theta): " << phaseAngle << " (degree)\n";
    cout << "VRmax: " << voltageRMax << " (Volt)\n";
    cout << "VLmax: " << voltageLMax << " (Volt)\n";
    cout << "VCmax: " << voltageCMax << " (Volt)\n";

    return 0;
}
