# Detailed Design Document

| **Author**              | `Authors Name`                                       |
|:------------------------|:-----------------------------------------------------|
| **Status**              | `Draft/Inspection/Approved`                          |
| **Version**             | `1.0`                                                |
| **Date**                | `dd/mm/yyyy`                                         |

## Introduction

Provide an overview of the entire document:

* Identify the system/product using any applicable names and/or version numbers.

### Purpose


### Scope



## Architectural Overview

This section describes where this module resides in the context of the software architecture
```plantuml
@startuml
rectangle UartApp #orange {
  rectangle Application
    rectangle MCU #green {
        rectangle LCD
        rectangle KeyPad
    }

    rectangle MCAL #skyblue {
            rectangle ADC
            rectangle UART
            rectangle DIO
            rectangle Register
    }
    
    Application -[hidden]-> MCU
    MCU -[hidden]-> MCAL
}
@enduml

```

### Assumptions & Constraints
Indicate constraints of the low level design and any assumptions appropriate for the design.

```plantuml
@startuml
(*) --> init
--> configure
if value > 15
  --> increment value
  --> (*)
else
  --> decrement value
  --> (*)
endif
@enduml
```

## Functional Description
The following chapter describes the software functionality.  The following is a list of suggested sections to be considered for inclusion.

## Implementation of the Module
This chapter discusses the detailed design of the module.

## Integration and Configuration
### Static Files
Typically a module consists of C and H files but other file types may exist. List all files that form this module

| File name | Contents                             |
|-----------|--------------------------------------|
| abc_xxx.c | Source code file, add detail         |
| abc.h     | Export Interface file                |
| abci.h    | Import and Module Configuration file |

### Include Structure

If there is a complex file structure e.g. more than one c-file or more than two h-files use a diagram to explain the relationship between the source and dependent include files.

```plantuml
@startuml
package "pkg" {
    [ABC_Init.c].>[ADC.h] : includes
    [ABC_Init.c]...>[ABCi.h]
    [ABC_Task.c]...>[ADC.h]
    [ABC_Task.c]...>[ABCi.h] : includes
    interface Interf3
    note left of ABC_Task.c: A top note
    ABC_Init.c ..> Interf3 : internal interface
}
@enduml
```

### Configuration
Any required hardware/software or system configuration that can be adjusted a header file shall be detailed in this section. This can be placed in the table below.
| Name | Value range | Description |
|------|-------------|-------------|
|      |             |             |
