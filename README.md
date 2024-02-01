# Car Service Program User Documentation

**Author:** Kornél Tóth  
**Course:** Programming 1  
**Date:** November 27, 2021

## Usage

1. **Launching the Program:**
   - Clone repo and navigate in the **/bin** directory
   - Ensure three text files: `customers.txt`, `cars.txt`, and `repairs.txt`
   - these text files have random data for showcasing purposes

3. **Adding Data:**
   - Select option 1 in the main menu.
   - Choose the data type to add (Customer, Car, or Repair).

     - *Adding a Customer:*
        - Format: `identifier [enter]`, `name [enter]`, `phone number [enter]`
   
     - *Adding a Car:*
        - Format: `license plate [enter]`, `car type [enter]`, `inspection date (yyyy mm dd) [enter]`, `owner's identifier [enter]`
   
     - *Adding a Repair:*
        - Format: `license plate [enter]`, `repair date (yyyy mm dd) [enter]`, `repair type [enter]`, `repair cost [enter]`

4. **Searching for Data:**
   - In submenu 2, search for cars or customers.

5. **Deleting Data:**
   - In submenu 3, delete customers or cars.

6. **Service History:**
   - Select option 4, enter a car's license plate to display its repair history.

7. **Displaying Data:**
   - In submenu 5, choose to display all cars, customers, or repairs.

8. **Expiring Soon:**
   - Select option 6 to display cars with upcoming technical inspections.

9. **Save Changes:**
   - Option 7 allows saving modifications without exiting the program.

10. **Save and Exit:**
   - Selecting option 0 in the main menu saves modifications and exits.

## Notes:
- Phone numbers and license plates limited to 15 characters.
- Names limited to 25 characters.
- Follow on-screen prompts for successful data entry.
