# Supermarket Billing System

This Supermarket Billing System is developed using the C programming language. It consists of two phases: Customer and Admin. In the Admin phase, the user can edit the details of the products, while in the Customer phase, the user can order the available products.

## Features

- Admin Phase:
  - Edit product details:
    - Add new products
    - Remove existing products
    - Update product information such as name, price, quantity, etc.
  - View product inventory

- Customer Phase:
  - Login & Signup Phase
  - Select products for purchase
  - Calculate and display the total bill amount
  - Generate a receipt with details of the purchased items

## Getting Started

To run this Supermarket Billing System, follow the steps below:

1. Clone the project repository from GitHub:

   ```shell
   git clone https://github.com/barath-sk17/supermarket_c_prog.git
   ```

2. Compile the source code using a C compiler:

   ```shell
   gcc supermarket_billing.c -o supermarket_billing
   ```

3. Run the compiled executable:

   ```shell
   ./supermarket_billing
   ```

4. Follow the on-screen instructions to navigate through the Customer and Admin phases.

## Usage

### Admin Phase

1. Enter the Admin credentials to access the Admin phase.

2. Use the provided options to perform the following actions:
   - Add a new product: Enter the product details such as name, price, quantity, etc.
   - Remove a product: Select the product to remove from the inventory.
   - Update product information: Choose a product to update and enter the new details.

### Customer Phase

1. Select the Customer option to enter the Customer phase.

2. Initially the customer has to login (i.e. if existing user, else he/she has to signup ) 

3. Shopping is initiated, once the signin valid then the customer can access the product of the market.

4. The system will calculate the total bill amount and display it on the screen.

5. A receipt will be generated with the details of the purchased items.

## Notes

- The Supermarket Billing System can be enhanced further by adding features like user authentication, database integration, and generating sales reports.

- The product details can be stored in a database or a text file for persistence.

- Make sure to update the product details periodically to reflect any changes in the inventory.

