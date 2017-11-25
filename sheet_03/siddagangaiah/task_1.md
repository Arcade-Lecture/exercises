
# Task 1

**Extreme Programming (XP)** 

1. XP is one among several agile software development methodologies. It was created with the purpose of producing high-quality software and handling ever-changing customer needs. 

    It's characterized by short development cycles with deliverables at its ends, pair programming, test-driven development, continuous code reviews and frequent communications between customer and manager/management and between developers.

    XP is driven by following principles: 
    * **Feedback:** Regular and frequent feedback is provided by the customer to the development team which steers the development of the product in the right direction. Any misunderstanding during requirement gathering phase can be rectified early in the development phase hence avoids costly rework at a later point in time. 
    
        Test suites are also sources of feedback. Automated tests are run for each contribution from the development team to make sure that the addition does not break the existing system.

    * **Simplicity:** Problems are broken down such that their solutions are extremely simple.

    * **Embracing change:** Customer's requirement change quite often during the software development cycle. XP provides ways to incorporate these changes quickly into the development process with little pain.

2. XP consists of 12 different activities divided into 4 categories. Below is a brief description of the same:

    * **Fine-scale feedback:** Being one of the important features of XP feedback is realized as follows: 

        * **Pair Programming**: Is a technique where two programmers one know as the driver and the other as observer work on a computer. Observer spots any future problems that might arise from the way of working of the driver. This helps the driver to concentrate on the problem at hand quickly without wasting time on thinking about possible consequences.

        * **Planning Game:** The planning process in XP is called planning game. This process is divided into two main phases called `Exploration phase` and `Iteration Phase`. Each of these phases is again subdivided into three phases which guides the development process.

        * **Test-Driven Development:** Before implementing any functionality, a unit test for it is planned and written. These tests help to direct the development process in the intended direction.

    * **Continous Process:** Contains set of activities which mandate integration of developers works to a shared repository many times a day. Following are the activities under this category.

        * **Continous Integration:** CI requires developers to commit their work, several times a day, to a central shared code base. On commit, test suites are run to check if the new change has any side effects on the system.

        * **Refactoring:** Code or design refactoring is done for better maintainability of the software product.

        * **Small Releases:** Software is delivered to the customer in small releases, frequently. This helps the customer to pitch in during the next development cycle for suggesting possible modifications to the design decisions.

    * **Shared Understanding:**
    
        * **Coding standard:** Set of rules are defined for development of software programs. Code confirming to these rules help developers to understand each others code quickly. It also helps in maintenance of code base.

        * **Collective Code Ownership:** collective ownership entitles every developer to modify any code in the code base. Accelerates the development process.

        * **Simple Design:** KISS principle is of the essence here. The simplest solution to a problem at hand is always preferred over other solutions.

        **System Metaphor:** Its a gist of the functionality of the software product. This should be evident from the way the code is written, in short code readability is highly desired.

    * **Programmer Welfare:** 

        * **Sustainable pace:** Work hours per week for each programmer are fixed in order not to overwork them. It they work overtime then there are options to rest those programmers in the subsequent development cycles.

3. Extreme Programming | Scrum
   ---------------------|------
   Iteration cycles last a week or two | Sprints last over a month or two
   Changes to the iteration plan is allowed during the iteration | Requirements are frozen after the sprint planning
   Customer defines priorities on the requirements and the product is developed in that order | Development team is allowed to choose the sequence for developing requirements which may be independent of their priority
   Has iterative development cycle | iterative development cycle

4. XP is more useful in scenarios where the requirements are not stable and customers require the product to be delivered incrementally and frequently. Scrum does not have the flexibility of XP as the sprint does not allow changes to the requirements.