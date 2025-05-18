#  Tank Registry Manager

**Tank Registry Manager** is a C++ terminal application that lets users create, edit, and manage tanks and their countries of origin using a PostgreSQL database. It uses modern C++ (C++17), libpqxx for database access, and follows clean modular design.

##  Features

- Add tanks with name, creation year, and associated country
- View all tanks
- Edit or delete specific tanks by ID
- List all available countries
- Display tanks by selected country
- PostgreSQL database integration using `libpqxx`
- Input validation and error handling
- Modular file structure using classes and clean CMake configuration

##  Technologies Used

- **C++17**
- **libpqxx** (PostgreSQL client library for C++)
- **PostgreSQL** (via Docker or local install)
- **CMake**
- MacOS/Linux compatible


##  How to Build

1. Make sure PostgreSQL is running (locally or in Docker)
2. Install libpqxx:
   brew install libpqxx   # Mac
   sudo apt install libpqxx-dev  # Linux
3. Build the project:
   mkdir build && cd build
   cmake ..
   make

4. Run it:
   ./webTanks

##  PostgreSQL Setup

Run this Docker command to start a local PostgreSQL server:

docker run --name tankdb -e POSTGRES_PASSWORD=secret -p 5432:5432 -d postgres

Ensure the database `tankdb` exists and your connection string matches:

pqxx::connection conn("host=localhost port=5432 dbname=tankdb user=postgres password=secret");

##  Future Improvements

- Add pagination and sorting
- Implement unit tests
- Build GUI version using Qt or web frontend

