#ifndef ALGO_ASS_1_PASSENGER_HXX
#define ALGO_ASS_1_PASSENGER_HXX

#include <string>

class Passenger {
private:
    std::string id;
    std::string firstName;
    std::string lastName;
    std::string gender;
    int age;
    std::string nationality;
    std::string airportName;
    std::string airportCountryCode;
    std::string countryName;
    std::string airportContinent;
    std::string continents;
    std::string departureDate;
    std::string arrivalAirport;
    std::string pilotName;
    std::string flightStatus;

public:

    Passenger(std::string id, std::string firstName, std::string lastName, std::string gender, int age,
              std::string nationality, std::string airportName, std::string airportCountryCode,
              std::string countryName, std::string airportContinent, std::string continents,
              std::string departureDate, std::string arrivalAirport, std::string pilotName,
              std::string flightStatus)
            : id(id), firstName(firstName), lastName(lastName), gender(gender),
              age(age), nationality(nationality), airportName(airportName),
              airportCountryCode(airportCountryCode), countryName(countryName),
              airportContinent(airportContinent), continents(continents),
              departureDate(departureDate), arrivalAirport(arrivalAirport),
              pilotName(pilotName), flightStatus(flightStatus) {
    }

    std::string getId() const {
        return id;
    }

    void setId(const std::string &newId) {
        id = newId;
    }

    std::string getFirstName() const {
        return firstName;
    }

    void setFirstName(const std::string &newFirstName) {
        firstName = newFirstName;
    }

    std::string getLastName() const {
        return lastName;
    }

    void setLastName(const std::string &newLastName) {
        lastName = newLastName;
    }

    std::string getGender() const {
        return gender;
    }

    void setGender(const std::string &newGender) {
        gender = newGender;
    }

    int getAge() const {
        return age;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    std::string getNationality() const {
        return nationality;
    }

    void setNationality(const std::string &newNationality) {
        nationality = newNationality;
    }

    std::string getAirportName() const {
        return airportName;
    }

    void setAirportName(const std::string &newAirportName) {
        airportName = newAirportName;
    }

    std::string getAirportCountryCode() const {
        return airportCountryCode;
    }

    void setAirportCountryCode(const std::string &newAirportCountryCode) {
        airportCountryCode = newAirportCountryCode;
    }

    std::string getCountryName() const {
        return countryName;
    }

    void setCountryName(const std::string &newCountryName) {
        countryName = newCountryName;
    }

    std::string getAirportContinent() const {
        return airportContinent;
    }

    void setAirportContinent(const std::string &newAirportContinent) {
        airportContinent = newAirportContinent;
    }

    std::string getContinents() const {
        return continents;
    }

    void setContinents(const std::string &newContinents) {
        continents = newContinents;
    }

    std::string getDepartureDate() const {
        return departureDate;
    }

    void setDepartureDate(const std::string &newDepartureDate) {
        departureDate = newDepartureDate;
    }

    std::string getArrivalAirport() const {
        return arrivalAirport;
    }

    void setArrivalAirport(const std::string &newArrivalAirport) {
        arrivalAirport = newArrivalAirport;
    }

    std::string getPilotName() const {
        return pilotName;
    }

    void setPilotName(const std::string &newPilotName) {
        pilotName = newPilotName;
    }

    std::string getFlightStatus() const {
        return flightStatus;
    }

    void setFlightStatus(const std::string &newFlightStatus) {
        flightStatus = newFlightStatus;
    }

};

#endif //ALGO_ASS_1_PASSENGER_HXX
