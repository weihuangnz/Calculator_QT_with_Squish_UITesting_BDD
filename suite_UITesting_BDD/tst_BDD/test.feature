# This is a sample .feature file
# Squish feature files use the Gherkin language for describing features, a short example
# is given below. You can find a more extensive introduction to the Gherkin format at
# https://github.com/cucumber/cucumber/wiki/Gherkin
Feature: Operations of mathematics


    Scenario: Calculating an Addition operation
        Given the Calculator is running
         When I input number 100
         And I input sign addition
         And I input number 200
         And I input sign equal 
         Then the results should be 300
          