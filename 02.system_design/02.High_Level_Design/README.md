# High-Level Design (HLD) - Quick Overview

High-Level Design is the **big-picture blueprint** of a system.

It answers:

* **What are we building?**
* **How will the major parts talk to each other?**
* **Where does data flow?**
* **How do we scale, secure, and keep it reliable?**

Think of it like planning a **city** before building it.

* HLD = roads, zones, power lines, water system, traffic flow
* LLD = the exact wiring of a traffic light, pipe diameter, building floor plans



## [ 1 ] What HLD Actually Means

HLD describes the **major components** of a software system and their interactions.

It usually includes:

* Frontend / client
* Backend services
* Database
* Cache
* Message queue
* Load balancer
* External integrations
* Auth / security layer
* Monitoring / logging

### Simple analogy

Imagine a food delivery app:

* Customer app places order
* Backend receives it
* Payment service checks payment
* Restaurant service forwards order
* Delivery service assigns driver
* Database stores everything
* Cache speeds up common data
* Queue handles async work like notifications

That whole system picture is HLD.



## [ 2 ] Why HLD Matters

Without HLD, teams often build things that work locally but break in real use.

HLD helps you think about:

* **Scalability** - what happens when users grow from 100 to 1 million?
* **Reliability** - what if one service fails?
* **Performance** - how do we respond faster?
* **Maintainability** - can the system be changed later?
* **Security** - how do we protect data and access?
* **Cost** - are we using too many resources?

### In one line

HLD helps you build a system that is not just functional, but **production-ready**.



## [ 3 ] HLD vs LLD

| Aspect             | HLD                                         | LLD                                     |
| ------------------ | ------------------------------------------- | --------------------------------------- |
| Focus              | Big picture                                 | Detailed implementation                 |
| Audience           | Architects, senior engineers, product teams | Developers, reviewers                   |
| Covers             | Services, data flow, scaling, integration   | Classes, methods, DB schema, algorithms |
| Questions answered | “What components do we need?”               | “How exactly do we code this?”          |
| Example            | API service + DB + cache + queue            | `UserService.createUser()` logic        |

### Easy way to remember

* **HLD = architecture**
* **LLD = implementation**



## [ 4 ] What an HLD Document Usually Contains

A good HLD usually has these parts:

### 1. Requirements

What the system must do.

* Functional requirements
* Non-functional requirements

### 2. System Overview

A short summary of the solution.

### 3. Architecture Diagram

A visual of major components.

### 4. Data Flow

How requests move through the system.

### 5. Key Components

What each service does.

### 6. Database Design

At a high level, not full schema details.

### 7. Scaling Strategy

How the system handles growth.

### 8. Security and Reliability

Auth, rate limiting, backups, retries, etc.

### 9. Trade-offs

What you chose and what you gave up.



## [ 5 ] A Typical HLD Flow

Here is the mental process:

```text
Requirements
    ↓
Identify main components
    ↓
Draw architecture
    ↓
Define data flow
    ↓
Add scaling + caching + queues
    ↓
Add security + failure handling
    ↓
Check trade-offs
```



## [ 6 ] Example: URL Shortener HLD

Let us take a simple system like **Bitly**.

### Requirement

* User gives a long URL
* System returns a short URL
* Short URL redirects to original URL
* Track click count

### High-level architecture

```text
User
  ↓
Frontend / API Gateway
  ↓
Backend Service
  ├── Database (store mappings)
  ├── Cache (fast redirect lookups)
  └── Analytics Queue (click tracking)
```

### Data flow

1. User submits long URL
2. Backend generates short code
3. Store `{short_code -> long_url}` in DB
4. Cache popular links
5. On redirect, read cache first
6. If cache miss, query DB
7. Log click event asynchronously

### Why this design works

* **Cache** makes redirects fast
* **Queue** avoids slowing down redirect requests
* **Database** stores source of truth



## [ 7 ] Key HLD Building Blocks

### A. Load Balancer

Distributes traffic across multiple servers.

```text
Users → Load Balancer → Server A / Server B / Server C
```

Why it matters:

* avoids overload
* improves uptime
* enables horizontal scaling



### B. Database

Stores persistent data.

Common choices:

* **SQL** for structured relational data
* **NoSQL** for flexible schema or very large scale

HLD question:

* What data goes where?
* Do we need read replicas?
* Do we need sharding later?


### C. Cache

Stores frequently used data temporarily.

Example:

* user profile
* trending posts
* session data

Why:

* faster reads
* lower DB load


### D. Message Queue

Used for background or delayed work.

Example:

* send email
* generate report
* process image
* notify users

Why:

* keeps API fast
* handles spikes better
* improves reliability



### E. Microservices / Services

Large systems often split into services.

Example:

* Auth service
* User service
* Payment service
* Notification service

Each service owns one responsibility.


## [ 8 ] Simple Diagram Example

### E-commerce app

```text
Client App
   ↓
API Gateway / Load Balancer
   ↓
┌──────────────────────────────┐
│ Backend Services             │
│ - Auth Service               │
│ - Product Service            │
│ - Cart Service               │
│ - Order Service              │
│ - Payment Service            │
└──────────────────────────────┘
   ↓              ↓
Database        Cache
   ↓              ↓
Message Queue → Email/SMS Worker
```

### What this tells us

* Users hit one entry point
* Different backend services handle different jobs
* Cache speeds up reads
* Queue handles async tasks
* Worker sends emails later



## [ 9 ] HLD Thinking: Questions You Should Ask

When designing a system, ask:

### Scale

* How many users?
* How many requests per second?
* Mostly reads or writes?

### Reliability

* What if a server crashes?
* What if the DB is down?
* Do we need retries or fallbacks?

### Performance

* Do we need cache?
* Can requests be async?
* What are the slow parts?

### Security

* Who can access this?
* How is authentication handled?
* How is data protected?

### Cost

* Can we use managed services?
* Do we need expensive infra now?
* What can stay simple for MVP?



## [ 10 ] HLD and Trade-offs

Almost every architecture choice is a trade-off.

| Choice        | Benefit               | Cost                          |
| ------------- | --------------------- | ----------------------------- |
| Cache         | Faster reads          | Stale data risk               |
| Queue         | Better responsiveness | More moving parts             |
| Microservices | Independent scaling   | More complexity               |
| SQL DB        | Strong consistency    | Less flexible at scale        |
| NoSQL         | Flexible and scalable | Harder joins and transactions |

Good HLD is not about perfect design.
It is about **choosing the right trade-offs for the problem**.



## [ 11 ] Common Mistakes in HLD

### 1. Overengineering too early

Building microservices for a tiny app is usually unnecessary.

### 2. Ignoring bottlenecks

A nice diagram means nothing if the DB becomes the only slow point.

### 3. Forgetting failure cases

Real systems fail. Good HLD plans for that.

### 4. No scaling plan

A system that works for 1,000 users may collapse at 100,000.

### 5. Vague component boundaries

If responsibilities overlap, maintenance becomes messy.



## [ 12 ] HLD in Interviews

In system design interviews, HLD is often the main focus.

You are usually expected to:

1. Clarify requirements
2. Estimate scale
3. Sketch architecture
4. Define APIs
5. Choose database
6. Add cache / queue / search if needed
7. Discuss bottlenecks
8. Discuss trade-offs

### Interview mindset

Do not jump straight into code.

Start broad:

> “Let us first define the core flow, identify the main services, and then optimize for scale and reliability.”

That sounds senior because it is the correct order of thinking.


## [ 13 ] A Very Small Template for HLD Notes

You can use this structure for any system:

```text
1. Requirements
2. Core entities
3. Major components
4. Data flow
5. API flow
6. Storage choice
7. Scaling strategy
8. Reliability strategy
9. Security strategy
10. Trade-offs
```



## [ 14 ] Final Intuition

### HLD is the answer to:

**“What should this system look like at a large scale?”**

It is the bridge between:

* product requirements
* system architecture
* future growth
* engineering execution

### One-liner

**HLD gives you the map before you start building the roads.**

