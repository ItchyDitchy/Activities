# Student Record Management System

A system designed by Ken Dylen R. Fernando as a side-project while studying in FEU Alabang as a freshman in Computer Science specialized in Software Engineering.

## Structure

```yml
Dashboard:
- Summary of students, courses and teachers.
- Recent notifications.
- Buttons for sub panels.
- Upcoming Events or Deadlines. -> Date Panel
Student Registration:
    Form:
        Personal:
            Name:
            - Prefix # String
            - Suffix # String
            - Given Name # String
            - Middle Name # String
            - Last Name # String
            Date of Birth:
            - Date # Long (Milliseconds)
            - => Age # Integer
            Marital Status: Marital/Civil Status # String
            Contacts:
                Emails: [] # String List
                Telephone Number: [] # String List
            Gender: Gender # String
            Nationality: Nationality # String
            Birth Place: Birth Place # String (City)
            Religious Affiliation: Religious Affiliation # String
            LRN: LRN # Long
            Country of Birth: Country of Birth # String (Country)
            Language Spoken: [] # String List
            Address:
                Mailing:
                    Country: Country # String
                    Region: Region # String
                    Province: Province # String
                    Town/City: Town/City # String
                    Barangay: Barangay # String
                    Street/House Number/Room/Floor: Street/House Number/Room/Floor # String
                    Zip Code: Zip Code # Integer
                Permanent:
                    Country: Country # String
                    Region: Region # String
                    Province: Province # String
                    Town/City: Town/City # String
                    Barangay: Barangay # String
                    Street/House Number/Room/Floor: Street/House Number/Room/Floor # String
                    Zip Code: Zip Code # Integer
        Academic:
            Semester:
                Id: # Start Milliseconds
                    Level: Level # String (Highschool/Senior Highschool/College)
                    Year: Year # Integer
                    Count: Count # Integer
                    Start: Start # Long (Milliseconds)
                    End: End # Long (Milliseconds)
                    Grade Mean: Grade Mean # Double (Out of 100)
Course Management:
- Course List + Editor
Teacher Management:
- Teacher List + Editor
Student Management:
- Student List + Editor
Notifications:
- Pending System
- Schedule System
Reports and Analytics:
- Visually Appealing Dashboard
About:
- Credits
```

## Credits

### Ken Dylen R. Fernando

Student of FEU Alabang  
Main Developer

## Changelogs

### 0.0.01 Initial Release

- README.md
- Interface
