# KRPS Mid-Semester: Complete Self-Contained Guide
**Knowledge Representation & Logical Reasoning: Propositional Logic and First-Order Logic**

> How to use: read top to bottom. Every part ends with a **Checkpoint** (3 questions with answers at the bottom of the part). Cover the answers, try, then check. Priority tags: 🔴 HIGH, 🟡 MEDIUM, 🟢 LOW. (Priorities are based on how fundamental a topic is and how much other topics depend on it, not a prediction of your paper.)

**Symbols used throughout (memorize this table first):**

| Symbol | Read as | Meaning |
|---|---|---|
| ¬P | not P | negation |
| P ∧ Q | P and Q | conjunction |
| P ∨ Q | P or Q (inclusive) | disjunction |
| P → Q | if P then Q | implication |
| P ↔ Q | P iff Q | biconditional |
| ⊨ | entails | semantic consequence |
| ⊢ | derives / proves | syntactic derivation |
| ⊥ | falsity / empty clause | contradiction |
| ∀ | for all | universal quantifier |
| ∃ | there exists | existential quantifier |

---

# 0. ROADMAP, CHECKLIST, AND THE BIG PICTURE

## 0.1 Emergency Study Schedule (≈ 4.5 hours)

| Time | What | Priority | How to study |
|---|---|---|---|
| 0:00–0:15 | Section 0 and Section 1 (foundations) | 🔴 | Understand |
| 0:15–0:45 | Part A: KB, agents, TELL/ASK | 🟡 | Understand + memorize the diagram |
| 0:45–1:15 | Part B.1–B.4: PL syntax, semantics, connectives | 🔴 | Memorize truth tables |
| 1:15–1:55 | Truth tables, equivalences, tautology (6 practice problems) | 🔴 | **Practice by hand** |
| 1:55–2:15 | Entailment, inference, soundness, completeness | 🔴 | Understand + memorize table |
| 2:15–2:25 | ☕ Break (walk, water) | | |
| 2:25–2:45 | Part C.1–C.3: validity, satisfiability, proof by contradiction, Modus Ponens, Horn | 🔴 | Understand |
| 2:45–3:30 | CNF conversion (6 problems) + Resolution (4 problems) | 🔴 | **Practice by hand. Most marks live here** |
| 3:30–4:15 | Part D/E: FOL + **translation practice** | 🔴 | Practice by hand |
| 4:15–4:30 | Part F: skim exam Q&A, read definitions | 🟡 | Memorize |
| Last 30 min before exam | Part J revision sheet only | | Read |

**Memorize:** 5 truth tables, equivalence list, CNF 4-step procedure, resolution rule, MP rule, entailment/soundness/completeness definitions, ∀ with →, ∃ with ∧.
**Understand (do not just memorize):** entailment vs inference, why resolution works (contradiction), quantifier translation.
**Practice by hand:** truth tables, CNF, resolution, FOL translation.
**Revise quickly:** KB agent architecture, definitions, comparison tables.

## 0.2 Syllabus Checklist (tick as you go)

**Part A: Knowledge-Based Systems (Section 2)**
- [ ] Knowledge Base · [ ] Knowledge-Based Systems · [ ] Models · [ ] Knowledge-Based Agents · [ ] Architecture and working · [ ] How agents use knowledge + inference to decide · [ ] TELL and ASK

**Part B: Propositional Logic (Section 3)**
- [ ] PL · [ ] PL as KR language · [ ] Syntax · [ ] Semantics · [ ] Connectives (¬ ∧ ∨ → ↔) · [ ] Truth tables · [ ] Logical equivalences · [ ] Tautology/contradiction/contingency · [ ] Logical reasoning · [ ] Entailment · [ ] Inference · [ ] Entailment vs inference · [ ] Soundness · [ ] Completeness

**Part C: Propositional Theorem Proving (Section 4)**
- [ ] Theorem proving · [ ] Validity · [ ] Satisfiability · [ ] Unsatisfiability · [ ] Validity–satisfiability relationship · [ ] Reduction to absurdity · [ ] Modus Ponens · [ ] Resolution · [ ] Horn clauses · [ ] CNF · [ ] CNF conversion · [ ] Applications of resolution

**Part D: Intro to FOL (Section 5)**
- [ ] PL vs FOL · [ ] Why FOL · [ ] Objects · [ ] Relations (unary, binary, n-ary) · [ ] Functions · [ ] Constants · [ ] Variables

**Part E: FOL Syntax and Semantics (Section 6)**
- [ ] Predicates · [ ] Variables · [ ] Constants · [ ] Functions · [ ] Quantifiers · [ ] ∀ · [ ] ∃ · [ ] Syntax · [ ] Semantics · [ ] Interpretation · [ ] Models · [ ] Domain of discourse · [ ] Free/bound variables · [ ] Scope · [ ] FOL as KR language · [ ] FOL KB

**Then:** Comparison tables (Section 7), Exam Q&A (Section 8), Problem bank (Section 9), Definitions (Section 10), Revision sheet (Section 11).

## 0.3 What is "Knowledge Representation and Reasoning"?

**Intuition.** A computer can store numbers and text, but it does not *know* things the way you do. You know "Socrates is a man" and "all men are mortal", and so you can figure out "Socrates is mortal" without anyone telling you. Knowledge Representation and Reasoning (KRR) answers two questions:

1. **Representation:** how do we write facts about the world in a precise language a computer can store?
2. **Reasoning:** how can the computer use those stored facts to work out *new* facts (and make decisions)?

**Formal.** *Knowledge representation* is the study of formal languages for encoding information about the world; *reasoning* is the process of deriving new information from represented knowledge using rules of inference.

```
 World facts ──(write in a formal language)──► Knowledge Base ──(reasoning)──► New facts / decisions
```

Logic is the most precise such language. This syllabus has two logics: **Propositional Logic** (simple, whole-statement facts) and **First-Order Logic** (more powerful: objects, relations, "all", "some").

---

# 1. FOUNDATIONS (🔴 read fully, it takes 15 minutes and everything depends on it)

**Statement (sentence).** A sentence you can sensibly call **true or false**.
- "It is raining." ✔ statement. "2 + 2 = 5." ✔ (false, but still a statement). "Close the door!" ✘ (command). "Is it raining?" ✘ (question).

**Proposition.** A statement with a definite truth value (T or F). We name it with a letter: `R` = "It is raining".

**Compound proposition.** Propositions joined by connectives (and, or, not, if-then). "It is raining **and** I have an umbrella" = `R ∧ U`.

**Premise.** A statement we are given/assume true. **Conclusion.** A statement we claim follows from the premises.
Example: Premises: "If it rains, the road is wet." "It rains." Conclusion: "The road is wet."

**Argument is valid** if whenever all premises are true, the conclusion must be true (we will formalize this as *entailment*).

**Literal.** A proposition letter or its negation: `P`, `¬P`. **Clause.** A disjunction (OR) of literals: `P ∨ ¬Q ∨ R`. (Needed for CNF and resolution.)

**Model (preview).** One complete assignment of T/F to every proposition letter = one "possible world". With letters P, Q, one model is "P=T, Q=F".

---

# 2. PART A: KNOWLEDGE-BASED SYSTEMS (🟡)

## 2.1 Knowledge Base (KB)

- **Intuition:** a notebook of facts and rules the agent has written down.
- **Formal definition:** A **Knowledge Base** is a set of sentences expressed in a formal knowledge representation language, each representing an assertion about the world.
- **Detail:** Sentences are of two kinds: *facts* ("Socrates is a man") and *rules* ("all men are mortal"). Sentences given without being derived from others are sometimes called **axioms**.
- **Example:** KB = { `Rain → WetRoad`, `Rain` }.
- **Exam answer:** "A knowledge base is a set of sentences in a formal language that represent what an agent knows about its world. The agent adds sentences using TELL and queries it using ASK."
- **Mistake:** thinking a KB is a database of rows. A KB can *infer* facts that were never stored.

## 2.2 Knowledge-Based System (KBS)

- **Intuition:** a program built around a KB plus a reasoning engine rather than hard-coded step-by-step instructions.
- **Formal:** A **knowledge-based system** is a system that stores knowledge in a KB and uses an **inference engine** to derive new knowledge and answer queries.
- **Two parts:** (1) **Knowledge base**: domain-specific content. (2) **Inference engine**: general reasoning procedure, independent of the domain.
- **Example:** A medical expert system: KB = disease rules; inference engine = applies rules to patient symptoms.
- **Key idea, declarative approach:** we *tell* the system what is true; we do not program how to decide. Change the KB and behavior changes, without rewriting the engine.

## 2.3 Models

- **Intuition:** a "possible world", one way things could be.
- **Formal:** A **model** is an assignment of truth values to all propositional symbols (in PL), i.e., a possible world in which every sentence is definitely true or false. We say *m is a model of α* (or *m satisfies α*) if α is true in m. Write **M(α)** = set of all models of α.
- **Example:** Symbols P, Q → 4 possible models: TT, TF, FT, FF. The sentence `P ∧ Q` is true only in model TT, so M(P ∧ Q) = {TT}.
- **Why it matters:** models are how we define *entailment*: KB ⊨ α iff M(KB) ⊆ M(α) (every world where KB is true is a world where α is true).
- **Mistake:** confusing "model" (a world / an assignment) with "model" in machine learning. Here it is only a possible world.

## 2.4 Knowledge-Based Agent: architecture and working

**Intuition:** an agent that carries a notebook (KB). Each moment it (1) writes down what it just sensed, (2) asks the notebook "what should I do?", (3) writes down what it chose, (4) acts.

**Formal:** A **knowledge-based agent** maintains a KB and, at each step, uses TELL and ASK with the KB to choose an action.

**Architecture diagram:**

```
          ┌────────────────────────────────────────────┐
          │              KNOWLEDGE-BASED AGENT         │
          │                                            │
 Percept  │   ┌───────────────────────────────────┐    │  Action
 ───────► │   │  INFERENCE ENGINE (domain-indep.) │    │ ───────►
 (sensors)│   │  uses logical rules to derive     │    │ (actuators)
          │   │  new sentences                    │    │
          │   └──────────────▲────────────────────┘    │
          │                  │ TELL / ASK              │
          │   ┌──────────────▼────────────────────┐    │
          │   │  KNOWLEDGE BASE (domain-specific) │    │
          │   │  sentences about the world        │    │
          │   └───────────────────────────────────┘    │
          └────────────────────────────────────────────┘
                          ▲  Environment ▼
```

**Working: the agent program (per time step t):**

```
function KB-AGENT(percept):
    TELL(KB, MAKE-PERCEPT-SENTENCE(percept, t))   // 1. record what I sense
    action ← ASK(KB, MAKE-ACTION-QUERY(t))        // 2. ask what to do now
    TELL(KB, MAKE-ACTION-SENTENCE(action, t))     // 3. record what I chose
    t ← t + 1
    return action                                 // 4. act
```

## 2.5 TELL and ASK

| Operation | Meaning | Example |
|---|---|---|
| **TELL(KB, s)** | Add sentence s to the KB | TELL(KB, "I smell a breeze at square [1,1]") |
| **ASK(KB, q)** | Query: is q (or what action) entailed by the KB? The answer is obtained by **inference** | ASK(KB, "Is there a pit at [1,2]?") |

Requirement: the answer to ASK must follow from what was TELLed (the KB must **entail** it).

## 2.6 How agents use knowledge and inference to decide

1. Perceive → convert percept to a sentence → TELL.
2. Inference engine checks which sentences follow (are *entailed*) from the KB.
3. If the KB entails "action A is best/safe", the agent performs A.
4. Because decisions are derived by logic, the agent can handle new situations it was never explicitly programmed for, as long as the knowledge covers them.

**Mini-example (Wumpus-style):** KB contains `¬B₁₁ → ¬P₁₂ ∧ ¬P₂₁` ("no breeze at [1,1] means no pits in neighbours"). Agent perceives `¬B₁₁`, TELLs it; inference gives `¬P₁₂`, `¬P₂₁`; agent concludes squares [1,2] and [2,1] are safe and moves there.

**Two levels (nice for 5 marks):** *Knowledge level*: what the agent knows, regardless of implementation. *Implementation level*: how the KB is stored (data structures, algorithms).

**Exam answer (5 marks):** Define KB agent; draw the diagram above; write the 3-line TELL/ASK loop; add one example.

### ✅ Checkpoint A
1. (Concept) What are the two main components of a knowledge-based system?
2. (Application) An agent sees "breeze". Which operation records this, and which operation decides the move?
3. (Concept) In `KB ⊨ α`, what must be true of the models?

*Answers:* 1) KB and inference engine. 2) TELL records; ASK (using inference) decides. 3) Every model of KB is also a model of α.

---

# 3. PART B: PROPOSITIONAL LOGIC (🔴 most of the exam lives from here on)

## 3.1 Propositional Logic and its role as a KR language

- **Intuition:** a tiny language where every fact is a whole statement (a letter) that is true or false, and we combine these with AND/OR/NOT/IF-THEN.
- **Formal:** **Propositional Logic (PL)** is a formal language whose sentences are built from proposition symbols and logical connectives, each sentence being true or false in a given model.
- **As a KR language:** it has (a) *syntax* (which strings are legal sentences), (b) *semantics* (what makes a sentence true/false), (c) an *inference* mechanism (derive new sentences). That triple is what makes a language a KR language.
- **Strengths:** simple, declarative, can say partial info ("P or Q"), compositional (meaning of a sentence comes from its parts).
- **Weakness:** cannot talk about objects or say "all". (This motivates FOL.)

## 3.2 Syntax of Propositional Logic

**Syntax = rules for forming legal sentences (shape only, no meaning).**

```
Sentence        → AtomicSentence | ComplexSentence
AtomicSentence  → True | False | P | Q | R | ...        (proposition symbols)
ComplexSentence → ( Sentence )
                | ¬ Sentence
                | Sentence ∧ Sentence
                | Sentence ∨ Sentence
                | Sentence → Sentence
                | Sentence ↔ Sentence
```

**Operator precedence (highest to lowest):** `¬`, `∧`, `∨`, `→`, `↔`. So `¬P ∨ Q ∧ R` means `(¬P) ∨ (Q ∧ R)`. When unsure, use brackets.

**Legal:** `P → (Q ∧ ¬R)`. **Illegal:** `P ∧ ∨ Q`, `→ P`.

## 3.3 Semantics of Propositional Logic

**Semantics = rules that give meaning (truth value) to sentences in a model.**

- A model fixes T/F for every symbol.
- `True` is always true; `False` always false.
- Compound sentences are evaluated **recursively** using the connective rules (truth tables below).

**Example.** Model m = {P=T, Q=F, R=T}. Evaluate `(P ∨ Q) ∧ ¬R`: `P∨Q` = T; `¬R` = F; `T ∧ F` = **F**.

## 3.4 The five connectives and their truth tables (🔴 MEMORIZE)

| P | Q | ¬P | P∧Q | P∨Q | P→Q | P↔Q |
|---|---|---|---|---|---|---|
| T | T | F | T | T | **T** | T |
| T | F | F | F | T | **F** | F |
| F | T | T | F | T | **T** | F |
| F | F | T | F | F | **T** | T |

**Memory tricks (these work):**
- **∧** is true *only* when both true.
- **∨** is false *only* when both false (inclusive OR: "at least one").
- **→** is false *only* when T→F (a promise is broken only if the condition happens but the result doesn't). If P is false, P→Q is **true** ("vacuously true").
- **↔** is true when both sides have the **same** value.
- **¬** flips.

**Reading each in English:** P→Q: "if P then Q", "P only if Q", "Q if P", "P is sufficient for Q". P↔Q: "P if and only if Q".
**Translation tips:** "P unless Q" ≡ `¬Q → P`. "P only if Q" = `P → Q`. "P if Q" = `Q → P`.

**Common mistake:** thinking P→Q means P causes Q, or that "F→anything" is false. It is **true**.

## 3.5 Truth tables: how to build and use them (🔴)

**Method:**
1. List the distinct variables, n of them.
2. **Number of rows = 2ⁿ** (2 vars → 4, 3 → 8, 4 → 16).
3. Fill variable columns systematically: first variable: first half T, second half F; next: alternate in blocks of half the size, etc. (for 3 vars: TTTT FFFF / TTFF TTFF / TFTF TFTF).
4. Add one column per sub-expression, **innermost first**, ending with the whole expression.
5. Read the last column:
   - all T → **tautology**; all F → **contradiction**; mixed → **contingency**.

**Types:**

| Type | Last column | Example | Also called |
|---|---|---|---|
| Tautology | all T | P ∨ ¬P | valid |
| Contradiction | all F | P ∧ ¬P | unsatisfiable |
| Contingency | some T, some F | P → Q | satisfiable but not valid |

**Verify an equivalence:** A ≡ B iff the columns of A and B are identical in every row (equivalently, A ↔ B is a tautology).

### Practice problems with full solutions

**Problem 1 (very simple). Classify P ∧ ¬P.**

| P | ¬P | P ∧ ¬P |
|---|---|---|
| T | F | F |
| F | T | F |

All F → **contradiction**.

**Problem 2 (simple). Classify P ∨ ¬P.**

| P | ¬P | P ∨ ¬P |
|---|---|---|
| T | F | T |
| F | T | T |

All T → **tautology** (law of excluded middle).

**Problem 3 (intermediate). Show P → Q ≡ ¬P ∨ Q.** (This equivalence powers CNF conversion.)

| P | Q | P→Q | ¬P | ¬P∨Q |
|---|---|---|---|---|
| T | T | T | F | T |
| T | F | F | F | F |
| F | T | T | T | T |
| F | F | T | T | T |

Columns 3 and 5 are identical → **equivalent**.

**Problem 4 (intermediate). Verify De Morgan: ¬(P ∧ Q) ≡ ¬P ∨ ¬Q.**

| P | Q | P∧Q | ¬(P∧Q) | ¬P | ¬Q | ¬P∨¬Q |
|---|---|---|---|---|---|---|
| T | T | T | F | F | F | F |
| T | F | F | T | F | T | T |
| F | T | F | T | T | F | T |
| F | F | F | T | T | T | T |

Columns 4 and 7 identical → **equivalent**.

**Problem 5 (exam level, contingency). Classify (P → Q) → (Q → P).**

| P | Q | P→Q | Q→P | (P→Q)→(Q→P) |
|---|---|---|---|---|
| T | T | T | T | T |
| T | F | F | T | T |
| F | T | T | F | **F** |
| F | F | T | T | T |

Mixed T and F → **contingency** (not a tautology; the converse of an implication is not equivalent to it).

**Problem 6 (exam level, 3 variables, tautology). Show ((P→Q) ∧ (Q→R)) → (P→R).** (Hypothetical syllogism)

| P | Q | R | P→Q | Q→R | (P→Q)∧(Q→R) | P→R | Whole |
|---|---|---|---|---|---|---|---|
| T | T | T | T | T | T | T | T |
| T | T | F | T | F | F | F | T |
| T | F | T | F | T | F | T | T |
| T | F | F | F | T | F | F | T |
| F | T | T | T | T | T | T | T |
| F | T | F | T | F | F | T | T |
| F | F | T | T | T | T | T | T |
| F | F | F | T | T | T | T | T |

All T → **tautology**. (Why each row works: when the antecedent is false the implication is automatically T; the only row with true antecedent is TTT, FTT, FFT, FFF, and in each the consequent P→R is T.)

## 3.6 Logical equivalences (🔴 MEMORIZE: this is your toolbox for CNF)

Two sentences are **logically equivalent (α ≡ β)** if they have the same truth value in every model.

| Name | Equivalence |
|---|---|
| Commutativity | α∧β ≡ β∧α ; α∨β ≡ β∨α |
| Associativity | (α∧β)∧γ ≡ α∧(β∧γ) ; (α∨β)∨γ ≡ α∨(β∨γ) |
| **Double negation** | ¬(¬α) ≡ α |
| **Implication elimination** | α→β ≡ ¬α∨β |
| **Contraposition** | α→β ≡ ¬β→¬α |
| **Biconditional elimination** | α↔β ≡ (α→β)∧(β→α) |
| **De Morgan** | ¬(α∧β) ≡ ¬α∨¬β ; ¬(α∨β) ≡ ¬α∧¬β |
| **Distributivity** | α∧(β∨γ) ≡ (α∧β)∨(α∧γ) ; α∨(β∧γ) ≡ (α∨β)∧(α∨γ) |
| Idempotence | α∧α ≡ α ; α∨α ≡ α |
| Excluded middle | α∨¬α ≡ True |
| Non-contradiction | α∧¬α ≡ False |
| Identity/Domination | α∧True ≡ α ; α∨False ≡ α ; α∨True ≡ True ; α∧False ≡ False |

**Why equivalences matter:** we can replace a sentence by an equivalent one without changing its meaning. This is how we simplify and convert to CNF.

**Derived equivalence worth knowing:** P→(Q→R) ≡ (P∧Q)→R. Proof: LHS = ¬P∨(¬Q∨R) = ¬P∨¬Q∨R; RHS = ¬(P∧Q)∨R = ¬P∨¬Q∨R. Same. ✔

**Mistakes:** (1) writing ¬(P∧Q) ≡ ¬P∧¬Q (wrong: De Morgan flips the connective). (2) Thinking P→Q ≡ Q→P (wrong, that's the converse). Contraposition ¬Q→¬P is the correct equivalent.

## 3.7 Logical Reasoning, Entailment, Inference, Soundness, Completeness (🔴)

**Logical reasoning.** The process of deriving new sentences (conclusions) from existing ones (premises/KB) so that the conclusions are *guaranteed* true whenever the premises are true.

### Entailment (semantic: about truth in worlds)
- **Intuition:** "If everything in my KB is true, then α *must* also be true; there is no possible world where KB holds but α fails."
- **Formal:** **KB ⊨ α** (KB entails α) iff **in every model in which KB is true, α is also true.** Equivalently M(KB) ⊆ M(α).
- **How to check by truth table:** list all models; keep rows where all KB sentences are T; check α is T in all of those rows.

**Example 1.** KB = {P, P→Q}. Rows where both true: only P=T,Q=T. Q is T there. So KB ⊨ Q ✔.
**Example 2.** KB = {P∨Q}. Does KB ⊨ P? Row P=F,Q=T makes KB true but P false → **No**.
**Example 3 (exam style).** KB = {P→Q, Q→R}. Does KB ⊨ P→R?

| P | Q | R | P→Q | Q→R | KB true? | P→R |
|---|---|---|---|---|---|---|
| T | T | T | T | T | yes | T |
| T | T | F | T | F | no | |
| T | F | T | F | T | no | |
| T | F | F | F | T | no | |
| F | T | T | T | T | yes | T |
| F | T | F | T | F | no | |
| F | F | T | T | T | yes | T |
| F | F | F | T | T | yes | T |

In all KB-true rows, P→R = T → **KB ⊨ P→R** ✔.

### Inference (syntactic: about symbol manipulation)
- **Intuition:** an *algorithm* that writes down new sentences from old ones by following fixed rules, without looking at "worlds".
- **Formal:** **KB ⊢ᵢ α** means α can be **derived** from KB by inference procedure *i* (a sequence of applications of inference rules such as Modus Ponens or Resolution).
- Entailment is a **fact** about the logic; inference is a **procedure** to discover that fact.

### Soundness and Completeness (how the two connect)
- **Sound (truth-preserving):** *i* derives only entailed sentences. If KB ⊢ᵢ α then KB ⊨ α. (No false conclusions.)
- **Complete:** *i* can derive **every** entailed sentence. If KB ⊨ α then KB ⊢ᵢ α. (Misses nothing.)

**Haystack analogy:** KB ⊨ α means "a needle is in the haystack" (a fact). Inference algorithm = your search. *Sound:* anything you pull out is really a needle. *Complete:* you can find every needle that exists.

An ideal inference system is **both sound and complete.** Examples: Modus Ponens is sound but **not complete** for general PL (it is complete for Horn KBs). Resolution (with refutation) is sound and **complete** for PL. An **unsound** procedure is useless (it proves false things); an incomplete one is limited but safe.

**Comparison: Entailment vs Inference**

| | Entailment (⊨) | Inference (⊢) |
|---|---|---|
| Kind | Semantic (about models/truth) | Syntactic (about symbols and rules) |
| Nature | A relationship that holds or not | A procedure/derivation |
| Defined by | Truth in all models | Applying inference rules step by step |
| Question answered | "Does α *have to be* true?" | "Can I *derive* α?" |
| Checked by | Truth table / model checking | Proof (MP, resolution) |
| Connection | Soundness: ⊢ ⇒ ⊨ ; Completeness: ⊨ ⇒ ⊢ | |

**Comparison: Soundness vs Completeness**

| | Soundness | Completeness |
|---|---|---|
| Statement | KB ⊢ α ⇒ KB ⊨ α | KB ⊨ α ⇒ KB ⊢ α |
| Meaning | Derives only true consequences | Derives all true consequences |
| Protects against | False conclusions | Missed conclusions |
| Failure means | Procedure is wrong/unreliable | Procedure is too weak |

**Mistakes:** mixing the two directions of the arrows; saying "entailment is a rule" (it is a relation, not a procedure).

### ✅ Checkpoint B
1. (Concept) Is `P→Q` true when P is false? Why?
2. (Application) Does {P∨Q, ¬P} entail Q? Justify with models.
3. (Problem) How many rows does a truth table with 5 variables have, and is `(P→Q)∨(Q→P)` a tautology?

*Answers:* 1) Yes; the "promise" isn't tested, so it is vacuously true. 2) Yes: ¬P forces P=F; then P∨Q forces Q=T. Only model P=F,Q=T, where Q is T. 3) 2⁵ = 32. Yes tautology: if P→Q is false then P=T,Q=F, so Q→P is... F→T = T. So the OR is always T.

---

# 4. PART C: PROPOSITIONAL THEOREM PROVING (🔴)

## 4.1 Theorem proving

- **Intuition:** instead of listing all worlds (truth tables explode: 2ⁿ rows), we *prove* a conclusion by chaining rules of inference, like a math proof.
- **Formal:** **Theorem proving** is showing that KB ⊨ α by applying inference rules to **derive** α from KB, without enumerating all models.
- **Why:** for n symbols a truth table needs 2ⁿ rows. Proofs can be much shorter.

## 4.2 Validity, Satisfiability, Unsatisfiability

| Term | Definition | Example |
|---|---|---|
| **Valid** | True in **all** models (= tautology) | P ∨ ¬P |
| **Satisfiable** | True in **at least one** model | P ∧ Q |
| **Unsatisfiable** | True in **no** model (= contradiction) | P ∧ ¬P |

**Relationships (memorize; they are the heart of theorem proving):**
- Valid ⇒ satisfiable. Unsatisfiable ⇒ not valid.
- **α is valid ⇔ ¬α is unsatisfiable.**
- α is satisfiable ⇔ ¬α is not valid.
- **Deduction theorem:** KB ⊨ α ⇔ (KB → α) is valid.
- **Refutation:** **KB ⊨ α ⇔ (KB ∧ ¬α) is unsatisfiable.**

```
       All sentences
   ┌────────────────────────────────┐
   │ Unsatisfiable (never true)     │  e.g. P∧¬P
   │ Satisfiable                    │
   │   ├─ Contingent (sometimes T)  │  e.g. P→Q
   │   └─ Valid (always T)          │  e.g. P∨¬P
   └────────────────────────────────┘
```

**Comparison table: Validity vs Satisfiability**

| | Validity | Satisfiability |
|---|---|---|
| True in | all models | at least one model |
| Same as | tautology | has a model |
| Test | all T in truth table | some T in truth table |
| Link | α valid ⇔ ¬α unsatisfiable | α satisfiable ⇔ ¬α not valid |

**Comparison table: Tautology vs Contradiction vs Contingency**

| | Tautology | Contradiction | Contingency |
|---|---|---|---|
| Truth values | always T | always F | sometimes T, sometimes F |
| Validity | valid | unsatisfiable | satisfiable, not valid |
| Example | P∨¬P | P∧¬P | P→Q |

## 4.3 Reduction to Absurdity (Proof by Contradiction)

- **Intuition:** to prove "Q is true", pretend Q is false and show this leads to an impossible situation. So Q must be true.
- **Formal:** To prove **KB ⊨ α**, assume **¬α**, add it to KB, and show **KB ∧ ¬α** is unsatisfiable (derive a contradiction, i.e., the empty clause ⊥). Then α must hold.
- **Example:** KB = {P→Q, P}; prove Q. Assume ¬Q. From P and P→Q get Q (by MP). But we assumed ¬Q: contradiction. So Q holds. ✔
- **Mistake:** forgetting to **negate** the goal before adding it.

## 4.4 Modus Ponens (🔴)

```
 P → Q        (rule: if P then Q)
 P            (fact: P is true)
 ───────
 ∴ Q          (conclusion)
```

- **Intuition:** a rule says "if P then Q"; you know P; so Q.
- **Formal:** From α→β and α, infer β. Sound.
- **How to recognize:** you need (1) an implication AND (2) its **antecedent** (the "if" part) stated as true. The conclusion is its **consequent**.
- **Related rule, Modus Tollens:** from P→Q and ¬Q infer ¬P.
- **Invalid look-alikes (common mistakes):** *Affirming the consequent*: P→Q, Q ∴ P ✘. *Denying the antecedent*: P→Q, ¬P ∴ ¬Q ✘.

**Example 1.** "If it rains, the ground is wet." "It rains." ∴ ground is wet.
**Example 2.** Student(Ravi) → Studies(Ravi); Student(Ravi) ∴ Studies(Ravi).
**Example 3 (multi-step).** Given: 1. A→B 2. B→C 3. C→D 4. A. Prove D.

| Step | Derivation | Reason |
|---|---|---|
| 5 | B | MP on 1, 4 |
| 6 | C | MP on 2, 5 |
| 7 | D | MP on 3, 6 |

**Example 4 (exam).** Given: 1. (P∧Q)→R 2. R→S 3. P 4. Q. Prove S.
5. P∧Q (∧-introduction from 3, 4) → 6. R (MP 1, 5) → 7. S (MP 2, 6). ✔

**Limitation:** MP alone isn't complete for general PL (e.g., from P∨Q, ¬P→R... it cannot reason by cases). It **is** complete for Horn KBs.

## 4.5 Resolution (🔴 PRIORITY TOPIC)

### Foundations
- **Literal:** a symbol or its negation: `P`, `¬P`.
- **Clause:** an OR of literals: `P ∨ ¬Q ∨ R`. A single literal is a clause (unit clause).
- **Complementary literals:** a literal and its negation: `P` and `¬P`.
- **Empty clause (⊥ or {}):** a clause with no literals; it is always **false** (an OR with nothing true). Deriving it means a contradiction.

### The resolution rule
```
   (A ∨ B)      (¬A ∨ C)
   ─────────────────────        "cancel the complementary pair A / ¬A
          (B ∨ C)                and join what's left"
```
General form: from `l₁ ∨ … ∨ lₖ` and `m₁ ∨ … ∨ mₙ`, where lᵢ and mⱼ are complementary, infer the OR of all remaining literals.

**Why valid (intuition):** in any world, either A is true or ¬A is true. If A is true, the second clause forces C. If ¬A is true, the first forces B. So B∨C holds either way.

**Special cases:**
- `P` and `¬P` → resolvent is **empty clause** ⊥ (contradiction!).
- `(¬P ∨ Q)` and `P` → `Q` (this *is* Modus Ponens, since ¬P∨Q ≡ P→Q).
- **Resolve only ONE complementary pair at a time.** `(P∨Q)` and `(¬P∨¬Q)` give `Q∨¬Q` or `P∨¬P`, both always true and useless; not the empty clause.

### Resolution refutation procedure (proof by contradiction)
To prove **KB ⊨ α**:
1. Convert every KB sentence to **CNF** (see 4.7) → set of clauses.
2. **Negate α**, convert to CNF, add its clauses.
3. Repeatedly pick two clauses with a complementary pair, add the **resolvent**.
4. If the **empty clause** appears → KB ∧ ¬α is unsatisfiable → **KB ⊨ α. Proved.**
5. If no new clauses can be generated and no empty clause → KB does **not** entail α.

```
 KB clauses + clauses of ¬α ──► resolve pairs ──► ... ──► ⊥ ?  yes → α proved
                                      └── nothing new, no ⊥ → α not entailed
```

Resolution is **sound** and **refutation-complete** (if KB ⊨ α, it will derive ⊥).

### Solved problems (every step explained)

**Problem R1 (simple). KB: P→Q, P. Prove Q.**
Clauses: C1 = ¬P∨Q (from P→Q), C2 = P. Negated goal: C3 = ¬Q.

| Step | Clause | From | Why |
|---|---|---|---|
| C4 | Q | C1, C2 | P and ¬P cancel |
| C5 | ⊥ | C4, C3 | Q and ¬Q cancel |

Empty clause derived → **Q is proved.**

**Problem R2 (intermediate). KB: P→Q, Q→R, P. Prove R.**
Clauses: C1 ¬P∨Q; C2 ¬Q∨R; C3 P; negated goal C4 ¬R.

| Step | Clause | From | Why |
|---|---|---|---|
| C5 | Q | C1, C3 | cancel P/¬P |
| C6 | R | C2, C5 | cancel Q/¬Q |
| C7 | ⊥ | C6, C4 | cancel R/¬R |

**R proved.**

**Problem R3 (exam level, case analysis, non-Horn). KB: P∨Q, P→R, Q→R. Prove R.**
Clauses: C1 P∨Q; C2 ¬P∨R; C3 ¬Q∨R; negated goal C4 ¬R.

| Step | Clause | From | Why |
|---|---|---|---|
| C5 | ¬P | C2, C4 | cancel R/¬R |
| C6 | ¬Q | C3, C4 | cancel R/¬R |
| C7 | Q | C1, C5 | cancel P/¬P |
| C8 | ⊥ | C7, C6 | cancel Q/¬Q |

**R proved.** (This is "reasoning by cases": either P or Q, both lead to R. MP alone cannot do this; resolution can.)

**Problem R4 (exam level, proving a negative, multi-literal). KB: (1) P→(Q∨R), (2) ¬Q, (3) ¬R. Prove ¬P.**
Clauses: C1 ¬P∨Q∨R; C2 ¬Q; C3 ¬R. Negated goal: ¬(¬P) = P → C4 P.

| Step | Clause | From | Why |
|---|---|---|---|
| C5 | Q∨R | C1, C4 | cancel ¬P/P |
| C6 | R | C5, C2 | cancel Q/¬Q |
| C7 | ⊥ | C6, C3 | cancel R/¬R |

**¬P proved.**

**Problem R5 (needs CNF conversion first). KB: (A∧B)→C, A, B. Prove C.**
(A∧B)→C ≡ ¬(A∧B)∨C ≡ ¬A∨¬B∨C. Clauses: C1 ¬A∨¬B∨C; C2 A; C3 B; negated goal C4 ¬C.
C5 ¬B∨C (C1,C2) → C6 C (C5,C3) → C7 ⊥ (C6,C4). **Proved.**

**Exam format reminder:** (1) list KB in CNF, (2) add negated goal, (3) numbered resolution table with "from" column, (4) conclude "empty clause derived, hence goal proved by refutation."

**Resolution and proof by contradiction:** they are the same idea. Adding ¬α and deriving ⊥ is the contradiction; resolution is the mechanical rule used to find it.

## 4.6 Horn Form / Horn Clauses

- **Intuition:** a restricted, easy type of rule: "if all of these are true, then this is true."
- **Formal:** A **Horn clause** is a clause (disjunction of literals) with **at most one positive literal**.
- **Types:**

| Type | Positive literals | Form | Meaning |
|---|---|---|---|
| **Definite clause** | exactly 1 | `¬A∨¬B∨C` ≡ `(A∧B)→C` | rule |
| **Fact** | exactly 1, nothing else | `C` | unconditional truth |
| **Goal / integrity clause** | 0 | `¬A∨¬B` ≡ `(A∧B)→False` | constraint / negated query |

- **Positive literal:** a symbol without ¬ (`C`). **Negative literal:** with ¬ (`¬A`).
- **Horn:** `¬P∨¬Q∨R`, `P`, `¬P∨¬Q`, `¬P∨Q`. **Not Horn:** `P∨Q` (two positive), `¬P∨Q∨R`, `P∨Q∨¬R`.
- **Why Horn is useful in AI:** (1) reads naturally as IF-THEN rules; (2) entailment can be decided in **linear time** using forward/backward chaining (just repeated Modus Ponens); (3) basis of logic programming (e.g., Prolog) and rule-based expert systems; (4) MP is complete for Horn KBs.
- **Limitation:** cannot express disjunction like "P or Q" or "not both... unless" in general.

| | Horn clause | General clause |
|---|---|---|
| Positive literals | at most 1 | any number |
| Example | ¬P∨¬Q∨R | P∨Q∨¬R |
| Inference | forward/backward chaining, linear time | resolution; entailment is NP-complete (co-NP) |
| Expressiveness | limited (no "P or Q") | full propositional power |
| Reads as | IF-THEN rule | arbitrary OR |

**Practice (identify):** (a) `¬A∨B` Horn (definite). (b) `A∨B` not Horn. (c) `¬A∨¬B` Horn (goal). (d) `C` Horn (fact). (e) `¬A∨B∨C` not Horn. (f) `A→B` ≡ ¬A∨B Horn. (g) `(A∧B)→(C∨D)` ≡ ¬A∨¬B∨C∨D not Horn.

## 4.7 Conjunctive Normal Form (CNF) (🔴 PRIORITY)

- **Intuition:** a standard "shape" for logic sentences: an AND of ORs. Resolution works only on this shape, like a machine that only accepts one kind of bolt.
- **Formal:** A sentence is in **CNF** if it is a **conjunction of clauses**, where each clause is a disjunction of literals: `(l₁₁∨l₁₂…) ∧ (l₂₁∨…) ∧ …`
- **Why required:** resolution rule is defined on clauses; every PL sentence has an equivalent CNF (so nothing is lost); a KB is then just a *set of clauses*.
- **Examples in CNF:** `(P∨¬Q)∧R`, `P`, `¬P∨Q`. **Not in CNF:** `P→Q`, `¬(P∧Q)`, `(P∧Q)∨R`.

### The 4-step conversion algorithm

| Step | Do this | Rule used (why valid) |
|---|---|---|
| 1 | Eliminate ↔ | α↔β ≡ (α→β)∧(β→α) |
| 2 | Eliminate → | α→β ≡ ¬α∨β |
| 3 | Push ¬ inward until it touches only symbols | ¬(α∧β)≡¬α∨¬β ; ¬(α∨β)≡¬α∧¬β ; ¬¬α≡α |
| 4 | Distribute ∨ over ∧ | α∨(β∧γ) ≡ (α∨β)∧(α∨γ) |
| 5 (tidy) | Remove duplicates; delete clauses containing P and ¬P | α∨¬α ≡ True; α∧True ≡ α |

Order matters: do 1 → 2 → 3 → 4.

### Solved problems (expression after EVERY step)

**C1 (beginner). P→Q.**
Step 2: `¬P∨Q`. Already CNF (one clause). ✔

**C2 (beginner). ¬(P∨Q).**
Step 3 (De Morgan): `¬P∧¬Q`. CNF = two unit clauses: `¬P`, `¬Q`.

**C3 (beginner). P↔Q.**
Step 1: `(P→Q)∧(Q→P)`. Step 2: `(¬P∨Q)∧(¬Q∨P)`. CNF ✔ (two clauses).

**C4 (intermediate). (P∧Q)→R.**
Step 2: `¬(P∧Q)∨R`. Step 3 (De Morgan): `(¬P∨¬Q)∨R` = `¬P∨¬Q∨R`. One clause ✔ (it is a Horn clause).

**C5 (intermediate). ¬(P→(Q∧R)).**
Step 2: `¬(¬P∨(Q∧R))`. Step 3: De Morgan → `¬¬P ∧ ¬(Q∧R)`; double negation → `P ∧ ¬(Q∧R)`; De Morgan → `P ∧ (¬Q∨¬R)`. CNF ✔ clauses: `P`, `¬Q∨¬R`.

**C6 (exam level). (P∨Q)→(R∧S).**
Step 2: `¬(P∨Q)∨(R∧S)`.
Step 3: `(¬P∧¬Q)∨(R∧S)`.
Step 4: distribute: `(¬P∨(R∧S)) ∧ (¬Q∨(R∧S))` → `(¬P∨R)∧(¬P∨S)∧(¬Q∨R)∧(¬Q∨S)`.
CNF ✔ (4 clauses). *Why 4:* (A∧B)∨(C∧D) = (A∨C)∧(A∨D)∧(B∨C)∧(B∨D).

**C7 (exam level). P↔(Q∨R).**
Step 1: `(P→(Q∨R))∧((Q∨R)→P)`.
Step 2: `(¬P∨Q∨R)∧(¬(Q∨R)∨P)`.
Step 3: `(¬P∨Q∨R)∧((¬Q∧¬R)∨P)`.
Step 4: `(¬P∨Q∨R)∧(¬Q∨P)∧(¬R∨P)`.
CNF ✔ (3 clauses).

**Common mistakes:** distributing ∧ over ∨ when you needed ∨ over ∧; forgetting to flip ∧/∨ in De Morgan; leaving → in the final answer; forgetting that a ↔ becomes *two* clauses (or more).

## 4.8 Applications of resolution in theorem proving
- Automated theorem provers and SAT-style solvers (DPLL/CDCL build on resolution ideas).
- Checking **entailment**: KB ⊨ α via refutation on KB ∧ ¬α.
- Checking **validity** (α is valid iff ¬α is unsatisfiable) and **consistency** of a KB.
- Logic programming (Prolog uses a resolution variant, SLD resolution, on Horn clauses), verification of hardware/software, planning, question-answering over a KB.
- Generalizes to FOL (with unification), the basis of most automated reasoning (beyond tomorrow's syllabus, 🟢).

### ✅ Checkpoint C
1. (Concept) What do you assume first when proving KB ⊨ α by resolution?
2. (Application) Is `¬A∨B∨C` Horn? Is `¬A∨¬B∨C`?
3. (Problem) Convert `P→(Q∧R)` to CNF.

*Answers:* 1) ¬α (the negated goal), added to the KB clauses. 2) First: no (two positives). Second: yes (definite). 3) `¬P∨(Q∧R)` → `(¬P∨Q)∧(¬P∨R)`.

---

# 5. PART D: INTRODUCTION TO FIRST-ORDER LOGIC (🔴)

## 5.1 Why propositional logic is not enough

Try to say "**All humans are mortal. Socrates is human. So Socrates is mortal**" in PL. You'd need symbols `HumanSocrates`, `MortalSocrates`, and the rule `HumanSocrates → MortalSocrates`. For *every* person you must write a separate rule, and PL cannot say "for *all* humans" in one sentence, nor see that `HumanSocrates` and `HumanPlato` are about the same property. PL treats each statement as an unbreakable atom.

Problems of PL: (1) no **objects**: can't talk *about* Socrates; (2) no **relations** between objects ("Ram is taller than Sita"); (3) no **quantification** ("all", "some", "none"); (4) knowledge base becomes huge or infinite.

## 5.2 What is First-Order Logic (FOL)?

**Intuition:** FOL = PL + the ability to talk about **things** (objects), their **properties/relationships**, and say "**for all**" / "**there exists**".

**Formal:** **First-order logic** (predicate logic) is a formal language whose sentences are built from **constants, variables, functions, predicates, connectives and quantifiers**, assuming the world consists of **objects** with **relations** and **functions** among them.

**World model in FOL:**
- **Objects:** things: Socrates, the number 2, the table.
- **Relations:** properties and links among objects.
  - **Unary** (1 object, a property): `Human(Socrates)`, `Even(4)`.
  - **Binary** (2 objects): `Loves(Ram, Sita)`, `Greater(5, 3)`.
  - **N-ary:** `Between(x, y, z)` (3-ary), `Gave(Ram, Book, Sita)`.
- **Functions:** map objects to a **single** object: `MotherOf(Ram)` (returns a person), `Plus(2,3)`.
- **Constants:** names of specific objects: `Socrates`, `Ram`, `2`.
- **Variables:** placeholders ranging over objects: x, y, z.

**Comparison: PL vs FOL**

| | Propositional Logic | First-Order Logic |
|---|---|---|
| Basic unit | whole proposition (P, Q) | objects, predicates, functions |
| Ontology (world is made of) | facts that are true/false | objects, relations, functions |
| Quantifiers | none | ∀, ∃ |
| Expressiveness | low (no "all/some") | high |
| Example | `RainsToday → WetRoad` | `∀x (Human(x) → Mortal(x))` |
| Structure | no internal structure of atoms | atoms have internal structure `Loves(Ram,Sita)` |
| Inference | truth tables, resolution (decidable) | resolution + unification (semi-decidable) |
| Size of KB for general rules | very large | compact |

---

# 6. PART E: FOL SYNTAX AND SEMANTICS (🔴)

## 6.1 Building blocks (differences table first)

| Element | What it is | Example | Evaluates to |
|---|---|---|---|
| **Constant** | name of one specific object | `Ram`, `2` | an object |
| **Variable** | placeholder for any object | `x`, `y` | an object (depending on assignment) |
| **Function** | maps object(s) to an object | `MotherOf(Ram)` | an **object** |
| **Predicate** | relation/property of object(s) | `Loves(Ram,Sita)`, `Human(x)` | **true/false** |

The key distinction: **functions return objects; predicates return truth values.** (`Loves(Ram, MotherOf(Ram))` is valid; `Loves(Ram, Human(Ram))` is not.)

## 6.2 Syntax of FOL

```
Sentence      → AtomicSentence | Sentence Connective Sentence
              | Quantifier Variable Sentence | ¬Sentence | (Sentence)
AtomicSentence→ Predicate(Term, ...) | Term = Term
Term          → Function(Term, ...) | Constant | Variable
Connective    → ∧ | ∨ | → | ↔
Quantifier    → ∀ | ∃
```
- **Term:** an expression that refers to an object (constant, variable, or function applied to terms).
- **Atomic sentence:** predicate applied to terms (or equality). Example: `Brother(Ram, Lakshman)`.
- **Complex sentence:** atomic sentences joined by connectives/quantifiers.
- **Equality:** `Father(Ram) = Dasharatha`.

## 6.3 Quantifiers (🔴)

**Universal quantifier ∀ ("for all", "every")**
- `∀x P(x)` is true iff P holds for **every** object x in the domain.
- Like a big AND: P(a) ∧ P(b) ∧ P(c) …
- **Golden rule: ∀ pairs with →.** `∀x (Student(x) → Smart(x))` = "every student is smart".

**Existential quantifier ∃ ("there exists", "some", "at least one")**
- `∃x P(x)` is true iff P holds for **at least one** object.
- Like a big OR: P(a) ∨ P(b) ∨ P(c) …
- **Golden rule: ∃ pairs with ∧.** `∃x (Student(x) ∧ Smart(x))` = "some student is smart".

**Why these rules? (the classic wrong translations)**
- `∀x (Student(x) ∧ Smart(x))` says *everything in the universe is a student and smart*. Wrong for "all students are smart".
- `∃x (Student(x) → Smart(x))` is true as soon as there is **one non-student** (because F→anything = T). It says almost nothing. Wrong for "some student is smart".

**Negation and quantifiers (De Morgan for quantifiers):**

| Equivalence | Reading |
|---|---|
| ¬∀x P(x) ≡ ∃x ¬P(x) | not everyone ⇒ someone doesn't |
| ¬∃x P(x) ≡ ∀x ¬P(x) | no one ⇒ everyone doesn't |
| ∀x P(x) ≡ ¬∃x ¬P(x) | |
| ∃x P(x) ≡ ¬∀x ¬P(x) | |

**Order of quantifiers:** same type commute: `∀x∀y ≡ ∀y∀x`, `∃x∃y ≡ ∃y∃x`. **Different types do NOT:**
- `∀x ∃y Loves(x,y)`: *everybody loves somebody* (the loved person may differ).
- `∃y ∀x Loves(x,y)`: *there is somebody whom everybody loves* (one person). Stronger; implies the first, not conversely.

**Comparison: ∀ vs ∃**

| | ∀ (Universal) | ∃ (Existential) |
|---|---|---|
| Meaning | for every object | for at least one object |
| Acts like | big AND | big OR |
| Usual connective | **→** | **∧** |
| Typical English | all, every, each, any | some, a, there is, at least one |
| Wrong pairing | ∧ (too strong) | → (too weak) |
| Negation | ¬∀ ≡ ∃¬ | ¬∃ ≡ ∀¬ |

## 6.4 Free and bound variables, scope (🔴)

- **Scope of a quantifier:** the sentence it applies to (the part after the quantified variable, usually in brackets).
- **Bound variable:** a variable that lies inside the scope of a quantifier for that variable.
- **Free variable:** a variable not bound by any quantifier.
- **Sentence (closed formula):** a formula with **no free variables**. Only sentences have a definite truth value in a model.

Examples:
1. `∀x (P(x) → Q(x))`: x bound everywhere. Sentence ✔.
2. `∀x P(x,y)`: x bound, **y free**. Not a sentence.
3. `∃x P(x) ∧ Q(x)`: scope of ∃x is only `P(x)`; the `x` in `Q(x)` is **free**. (Use brackets `∃x (P(x) ∧ Q(x))` to include both.)
4. `∀x (P(x) → ∃y R(x,y))`: x and y both bound; sentence ✔.

**Mistake:** thinking brackets don't matter. They define scope.

## 6.5 Semantics: Interpretation, Model, Domain of discourse

- **Domain of discourse (D):** the non-empty set of all objects we are talking about (e.g., all students in a class; all natural numbers). Quantifiers range over D.
- **Interpretation:** an assignment of meaning to the symbols:
  - each **constant** → an object in D;
  - each **function symbol** → a function on D;
  - each **predicate symbol** → a relation on D (the set of tuples for which it's true).
- **Truth in an interpretation:** `P(t₁..tₙ)` is true iff the tuple of objects referred to by t₁..tₙ is in the relation assigned to P; connectives as in PL; `∀x S` true iff S true for **every** object in D; `∃x S` true iff true for **some** object in D.
- **Model:** an interpretation (with its domain) in which a sentence/KB is **true**. (Convention note: some textbooks, e.g. AIMA, call the domain + interpretation a "model"; others reserve "model" for an interpretation that makes the sentence true. The second usage is the standard exam one: *a model of a KB is an interpretation under which all KB sentences are true*.)

**Worked example.** D = {Alice, Bob}. Constants: Alice→Alice, Bob→Bob. Predicate Likes = {(Alice, Bob)}.
- `Likes(Alice,Bob)` → **T**.
- `∃x Likes(x,Bob)` → T (x = Alice).
- `∀x ∃y Likes(x,y)` → check x = Bob: Bob likes nobody → **F**.
- `∀x ∀y Likes(x,y)` → **F** (Bob does not like Alice). Point: the same sentence can be true or false depending on the interpretation.

**Comparison: Interpretation vs Model**

| | Interpretation | Model |
|---|---|---|
| What | any assignment of meanings (domain, constants, functions, predicates) | an interpretation in which the sentence(s) are **true** |
| Truth of sentence | may be T or F | T by definition |
| Example | Likes = {(Alice,Bob)} (makes some sentences T, others F) | the same interpretation, but for `Likes(Alice,Bob)` it is a model |

**Comparison: Syntax vs Semantics**

| | Syntax | Semantics |
|---|---|---|
| Concerns | form/structure of sentences | meaning/truth of sentences |
| Question | "Is this string well-formed?" | "Is this sentence true in this model?" |
| Defined by | grammar (BNF) | truth tables / interpretations |
| Example (PL) | `P ∧ ∨ Q` is illegal | `P ∧ Q` is T iff both T |
| Example (FOL) | `Loves(Ram)` bad arity | `Loves(Ram,Sita)` is T iff the pair is in the relation |

## 6.6 FOL as a Knowledge Representation Language and building a FOL KB

**FOL as a KR language:** it has syntax (terms, atoms, quantifiers), semantics (interpretations/models), and inference (e.g., universal instantiation + Modus Ponens, resolution). It can represent **objects, properties, relations, general laws**, which is why it is the standard logic for KR.

**Steps to build a FOL KB:**
1. Choose the **domain** (what objects exist).
2. Choose **vocabulary**: constants, predicates (with arity), functions.
3. Write **facts** (ground atomic sentences): `Human(Socrates)`.
4. Write **rules** (quantified sentences): `∀x (Human(x) → Mortal(x))`.
5. **TELL** them into the KB, then **ASK** queries.

**Example KB (family):**
```
Parent(Dasharatha, Ram)                   fact
Parent(Dasharatha, Lakshman)              fact
Male(Ram)  Male(Lakshman)                 facts
∀x ∀y (Parent(x,y) ∧ Male(y) → Son(y,x))  rule: sons
∀x ∀y ∀z (Parent(x,y) ∧ Parent(x,z) ∧ y≠z → Sibling(y,z))  rule
```
ASK(KB, `Son(Ram, Dasharatha)`) → True.

**Inference with quantifiers:** *Universal instantiation (UI):* from `∀x P(x)` infer `P(a)` for any constant a. Then apply MP.
- KB: `∀x (Human(x)→Mortal(x))`, `Human(Socrates)`.
- UI with x=Socrates: `Human(Socrates)→Mortal(Socrates)`. MP with `Human(Socrates)` → **`Mortal(Socrates)`**. ✔

## 6.7 ENGLISH → FOL TRANSLATION (🔴 PRACTICE THIS MOST)

### The recipe
1. **Identify the predicates and constants** (nouns/adjectives/verbs → predicates; names → constants).
2. **Find the quantifier words:** *all, every, each, any → ∀; some, a, there is, at least one → ∃; no, nobody, none → ¬∃ (or ∀¬); not all → ¬∀ (or ∃¬).*
3. **Choose the connective:** ∀ → **→**; ∃ → **∧**.
4. Handle nested quantifiers left to right as the English reads.
5. **Check:** read your formula back in English. Test with a tiny domain (e.g. a non-student): does the formula stay true when it should?
6. For people-only statements you may write `Person(x)` or assume the domain is people; if the domain is mixed, include the type predicate.

### The 10 required sentences

| # | English | FOL | Explanation |
|---|---|---|---|
| 1 | All humans are mortal. | `∀x (Human(x) → Mortal(x))` | "all" → ∀ with → |
| 2 | Socrates is a human. | `Human(Socrates)` | constant, no quantifier |
| 3 | Some students are intelligent. | `∃x (Student(x) ∧ Intelligent(x))` | "some" → ∃ with ∧ |
| 4 | Every student likes at least one subject. | `∀x (Student(x) → ∃y (Subject(y) ∧ Likes(x,y)))` | ∀ outside; inside, "at least one subject" is ∃ with ∧ |
| 5 | Nobody likes everybody. | `¬∃x ∀y Likes(x,y)` ≡ `∀x ∃y ¬Likes(x,y)` | negation pushes through: "everyone fails to like someone". (Typed: `¬∃x (Person(x) ∧ ∀y (Person(y) → Likes(x,y)))`) |
| 6 | Every teacher teaches some student. | `∀x (Teacher(x) → ∃y (Student(y) ∧ Teaches(x,y)))` | same pattern as 4 |
| 7 | There exists a person who loves everyone. | `∃x (Person(x) ∧ ∀y (Person(y) → Loves(x,y)))` | ∃ with ∧; inside, ∀ with → |
| 8 | All birds can fly. | `∀x (Bird(x) → CanFly(x))` | |
| 9 | Some birds cannot fly. | `∃x (Bird(x) ∧ ¬CanFly(x))` | this is exactly ¬(sentence 8) |
| 10 | Every student who studies hard passes the examination. | `∀x ((Student(x) ∧ StudiesHard(x)) → Passes(x, Exam))` | the condition "student who studies hard" goes into the antecedent |

**Check on 8/9:** ¬∀x (Bird(x)→CanFly(x)) ≡ ∃x ¬(¬Bird(x)∨CanFly(x)) ≡ ∃x (Bird(x) ∧ ¬CanFly(x)) ✔.

### 12 additional practice sentences (with answers and reasons)

| # | English | FOL | Why |
|---|---|---|---|
| 11 | No student is perfect. | `¬∃x (Student(x) ∧ Perfect(x))` ≡ `∀x (Student(x) → ¬Perfect(x))` | "no" = not exists |
| 12 | Not all students are lazy. | `¬∀x (Student(x) → Lazy(x))` ≡ `∃x (Student(x) ∧ ¬Lazy(x))` | negate ∀ → ∃ |
| 13 | Everyone loves someone. | `∀x ∃y Loves(x,y)` | ∀∃: loved person can differ |
| 14 | Someone is loved by everyone. | `∃y ∀x Loves(x,y)` | ∃∀: one single person. Different from 13 |
| 15 | Everyone who is rich or famous is happy. | `∀x ((Rich(x) ∨ Famous(x)) → Happy(x))` | OR in the antecedent |
| 16 | Some student passed every exam. | `∃x (Student(x) ∧ ∀y (Exam(y) → Passed(x,y)))` | ∃ ∧ then ∀ → |
| 17 | Only students get scholarships. | `∀x (Scholarship(x) → Student(x))` | "only A are B" means B → A (not A → B) |
| 18 | Brothers are siblings. | `∀x ∀y (Brother(x,y) → Sibling(x,y))` | two variables |
| 19 | Everyone loves their mother. | `∀x Loves(x, MotherOf(x))` | function `MotherOf` returns an object |
| 20 | Exactly one king exists. | `∃x (King(x) ∧ ∀y (King(y) → y = x))` | uniqueness with equality |
| 21 | Every student takes a course taught by Rao. | `∀x (Student(x) → ∃y (Course(y) ∧ Takes(x,y) ∧ Teaches(Rao,y)))` | ∃ with ∧ of several conditions |
| 22 | If someone is a parent, then they have a child. | `∀x (Parent(x) → ∃y Child(y,x))` | ∃ inside a rule |

### Mistakes and how to avoid them
1. `∀x (A(x) ∧ B(x))` for "all A are B" → use **→**.
2. `∃x (A(x) → B(x))` for "some A is B" → use **∧**.
3. Mixing quantifier order (13 vs 14).
4. Forgetting that "nobody/none" needs ¬ (¬∃ or ∀¬).
5. Using a predicate where a function is needed (or reverse).
6. Leaving a variable free (check every variable is bound by a quantifier).
7. "Only" direction: "only A are B" = ∀x (B(x)→A(x)).

### ✅ Checkpoint D/E
1. (Concept) Name two things FOL can express that PL cannot.
2. (Application) Translate "Some cats are not black."
3. (Problem) Is the variable y bound in `∀x (P(x) → Q(y))`? Translate "Every student loves some teacher".

*Answers:* 1) Objects/relations and quantification ("all", "some"). 2) `∃x (Cat(x) ∧ ¬Black(x))`. 3) y is **free**. Translation: `∀x (Student(x) → ∃y (Teacher(y) ∧ Loves(x,y)))`.

---

# 7. COMPARISON TABLES (consolidated, memorize for 2–5 marks)

**7.1 Propositional Logic vs First-Order Logic**

| Feature | PL | FOL |
|---|---|---|
| Atoms | whole statements | predicates over objects |
| Objects/relations | not represented | represented |
| Quantifiers | no | ∀, ∃ |
| Power | low | high |
| Compactness | needs one rule per object | one general rule |

**7.2 Syntax vs Semantics**

| Syntax | Semantics |
|---|---|
| structure/grammar | meaning/truth |
| well-formed or not | true or false in a model |

**7.3 Entailment vs Inference**

| Entailment ⊨ | Inference ⊢ |
|---|---|
| semantic; true in all models | syntactic; derived by rules |
| a relation | a procedure |
| ideal definition | way of computing it |

**7.4 Soundness vs Completeness**

| Soundness | Completeness |
|---|---|
| ⊢ ⇒ ⊨ | ⊨ ⇒ ⊢ |
| no false conclusions | no missed conclusions |

**7.5 Validity vs Satisfiability**

| Valid | Satisfiable |
|---|---|
| true in all models | true in ≥ 1 model |
| α valid ⇔ ¬α unsatisfiable | α sat ⇔ ¬α not valid |

**7.6 Tautology vs Contradiction vs Contingency**

| Tautology | Contradiction | Contingency |
|---|---|---|
| always T | always F | mixed |
| P∨¬P | P∧¬P | P→Q |

**7.7 Modus Ponens vs Resolution**

| | Modus Ponens | Resolution |
|---|---|---|
| Rule | α→β, α ⊢ β | (A∨B), (¬A∨C) ⊢ (B∨C) |
| Input form | implication + fact | two clauses (CNF) |
| Power | complete only for Horn KBs | sound and refutation-complete for all PL |
| Use | forward chaining | automated theorem proving |
| Relation | MP is a special case of resolution (¬P∨Q with P gives Q) | |

**7.8 Horn Clauses vs General Clauses**: see table in 4.6.

**7.9 Universal vs Existential Quantifiers**: see table in 6.3.

**7.10 Constants vs Variables vs Functions vs Predicates**

| | Constant | Variable | Function | Predicate |
|---|---|---|---|---|
| Stands for | specific object | any object | mapping to an object | relation/property |
| Returns | object | object | object | truth value |
| Example | Ram | x | MotherOf(x) | Loves(x,y) |

**7.11 Interpretation vs Model**: see table in 6.5.

---

# 8. EXAM-ORIENTED THEORY Q&A

## 8.A Fifteen 2-mark questions

1. **Define a knowledge base.** A set of sentences in a formal language representing what an agent knows about the world.
2. **What is a knowledge-based agent?** An agent that maintains a KB and uses TELL and ASK with inference to choose actions.
3. **What do TELL and ASK do?** TELL adds a sentence to the KB; ASK queries the KB, answered by inference.
4. **What is a model in logic?** An assignment of truth values to all symbols (a possible world). A model of α is one where α is true.
5. **Define a proposition.** A declarative statement that is either true or false.
6. **When is P→Q false?** Only when P is true and Q is false.
7. **Define tautology with an example.** A sentence true in every model; e.g., P∨¬P.
8. **Define entailment.** KB ⊨ α iff α is true in every model in which KB is true.
9. **Define a sound inference procedure.** One that derives only sentences entailed by the KB.
10. **Define a complete inference procedure.** One that can derive every sentence entailed by the KB.
11. **State Modus Ponens.** From α→β and α, infer β.
12. **What are a literal and a clause?** Literal: a symbol or its negation. Clause: a disjunction of literals.
13. **What is a Horn clause?** A clause with at most one positive literal.
14. **Define CNF.** A conjunction of clauses (an AND of ORs of literals).
15. **What is a free variable?** A variable not within the scope of any quantifier that binds it.

## 8.B Fifteen 5-mark questions with model answers

**1. Explain the architecture of a knowledge-based agent.** A KB agent has (i) a **knowledge base** (domain-specific sentences) and (ii) an **inference engine** (domain-independent reasoning). It interacts through TELL and ASK. Per cycle: perceive → TELL(KB, percept sentence) → ASK(KB, action query) → TELL(KB, action sentence) → execute. *(Draw the diagram of 2.4.)* Because the agent reasons over declarative knowledge, adding facts changes behavior without reprogramming.

**2. Explain the syntax of propositional logic.** Atomic sentences: True, False, symbols P,Q,R. Complex: ¬S, S₁∧S₂, S₁∨S₂, S₁→S₂, S₁↔S₂, (S). Precedence ¬ > ∧ > ∨ > → > ↔. *(Write the BNF of 3.2.)* Syntax specifies only the legal form, not the meaning.

**3. Explain the semantics of propositional logic.** A model assigns T/F to every symbol. True is always true, False always false. Truth of ¬S, S₁∧S₂, S₁∨S₂, S₁→S₂, S₁↔S₂ is computed recursively using the truth table of the connective *(write the table of 3.4)*. Example: in P=T,Q=F, (P∨Q)∧¬Q = T∧T = T.

**4. Differentiate entailment and inference.** *(Reproduce the table in 3.7: semantic vs syntactic, relation vs procedure, truth-in-all-models vs derivation; link: soundness and completeness.)* Add: entailment is the ideal, inference is how a machine finds it.

**5. Differentiate validity and satisfiability.** *(Table 4.2.)* A sentence is valid if true in all models (tautology), satisfiable if true in some model, unsatisfiable if true in none. α is valid iff ¬α is unsatisfiable. KB ⊨ α iff KB ∧ ¬α is unsatisfiable.

**6. Explain proof by contradiction (reduction to absurdity).** To prove KB ⊨ α, assume ¬α, add to KB, and derive a contradiction (empty clause). Since KB ∧ ¬α is then unsatisfiable, α must be true in all models of KB. Example: KB={P→Q,P}, assume ¬Q; MP gives Q; contradiction; hence Q.

**7. Explain the resolution inference rule with an example.** From clauses (A∨B) and (¬A∨C) infer (B∨C). Complementary literals A and ¬A are removed. Special case: P and ¬P give the empty clause. *Example:* (P∨Q), (¬P∨R) ⊢ (Q∨R). It is sound and refutation-complete; used with CNF.

**8. Explain the steps of converting a sentence to CNF.** (1) Eliminate ↔: α↔β ≡ (α→β)∧(β→α). (2) Eliminate →: α→β ≡ ¬α∨β. (3) Move ¬ inwards using De Morgan and double negation. (4) Distribute ∨ over ∧. (5) Simplify. *Example:* P→(Q∧R) ⇒ ¬P∨(Q∧R) ⇒ (¬P∨Q)∧(¬P∨R).

**9. What are Horn clauses? Why are they important?** A Horn clause has at most one positive literal. Definite clause: exactly one (¬A∨¬B∨C ≡ A∧B→C); fact: just C; goal clause: no positive literal. Importance: they model IF-THEN rules; entailment is decidable in linear time by forward/backward chaining; Modus Ponens is complete for them; they underlie Prolog and expert systems.

**10. Compare PL and FOL; why do we need FOL?** *(Table 5.2.)* PL cannot represent objects, relations or generalizations ("all humans are mortal") without one sentence per object. FOL introduces predicates, functions, constants, variables, ∀ and ∃, so general knowledge is expressed compactly.

**11. Explain the syntax of FOL.** Terms: constants, variables, f(t₁..tₙ). Atomic sentences: P(t₁..tₙ) or t₁=t₂. Complex: ¬S, S∧S, S∨S, S→S, S↔S, ∀x S, ∃x S. *(Write the BNF of 6.2.)* Examples: Human(Socrates), ∀x (Human(x)→Mortal(x)).

**12. Explain universal and existential quantifiers with examples.** ∀x P(x): P true for all objects (conjunction); ∃x P(x): true for at least one (disjunction). Pairings: ∀ with →, ∃ with ∧. Examples: ∀x (Student(x)→Smart(x)); ∃x (Student(x)∧Smart(x)). Negations: ¬∀x P ≡ ∃x ¬P; ¬∃x P ≡ ∀x ¬P.

**13. Explain interpretation, model and domain of discourse.** Domain: non-empty set of objects considered. Interpretation: maps constants→objects, functions→functions on the domain, predicates→relations on the domain. Model: an interpretation in which the sentences of the KB are true. Truth of ∀/∃ is evaluated over the domain. *(Example in 6.5.)*

**14. Explain free and bound variables and scope.** Scope of a quantifier is the sentence it governs. A variable inside the scope of its quantifier is bound; otherwise free. Sentences have no free variables. Example: in ∀x P(x,y), x bound, y free; in ∃x P(x) ∧ Q(x), the second x is free.

**15. Explain soundness and completeness.** *(Definitions + table 3.7.)* Sound: KB ⊢ α ⇒ KB ⊨ α. Complete: KB ⊨ α ⇒ KB ⊢ α. A good inference algorithm is both. Modus Ponens: sound, complete only for Horn KBs; Resolution: sound and refutation-complete.

## 8.C Five 10-mark questions with model answers

**10-1. Describe knowledge-based agents: architecture, TELL/ASK, and how they use inference to make decisions.**
(1) *Definition:* an agent with a KB and an inference engine. (2) *KB:* set of sentences in a formal language. (3) *Inference engine:* derives new sentences, domain-independent. (4) *Architecture:* draw diagram 2.4. (5) *Operations:* TELL adds knowledge; ASK queries entailed knowledge. (6) *Program:* the 4-line KB-AGENT function of 2.4. (7) *Decision:* percept is TELLed; inference determines which actions are entailed to be best or safe; the action is executed and recorded. (8) *Example:* Wumpus world: ¬B₁₁ ⇒ ¬P₁₂ ∧ ¬P₂₁, so the neighbours are safe. (9) *Advantages:* declarative, modular, can learn by adding facts, behaves sensibly in unforeseen situations.

**10-2. Explain resolution theorem proving for propositional logic with a worked example.**
Define literal, clause, complementary literals, empty clause. State the rule. Give the refutation algorithm (5 steps in 4.5). State soundness and refutation-completeness. Worked example: R3 (KB: P∨Q, P→R, Q→R; prove R) or R2. Conclude "empty clause derived; hence KB ⊨ goal." Mention link with proof by contradiction and applications (SAT solvers, Prolog, verification).

**10-3. Explain conversion to CNF with a full worked example and say why CNF is needed.**
Define CNF/clause/literal. Why: resolution needs clauses; every sentence has an equivalent CNF. Give the 4-step algorithm with the equivalence used at each step *(table in 4.7)*. Worked example: C7 `P↔(Q∨R)` with every step shown, ending in `(¬P∨Q∨R)∧(¬Q∨P)∧(¬R∨P)`. Mention common mistakes.

**10-4. FOL as a knowledge representation language: syntax, semantics, KB construction.**
Why FOL (limits of PL). Ontology: objects, relations, functions. Syntax BNF (6.2). Quantifiers with rules (∀→, ∃∧). Semantics: domain, interpretation, model, truth of ∀/∃. Free/bound variables. Steps to build a KB (6.6) and the Socrates / family example with UI + MP. Add 3 translations from 6.7.

**10-5. Propositional logic as a KR language: syntax, semantics, equivalences, entailment, and the truth-table method.**
Syntax BNF (3.2); semantics with five truth tables (3.4); equivalence list (3.6); define entailment and show a truth-table check of {P→Q, Q→R} ⊨ P→R (3.7, 8 rows); classify tautology/contradiction/contingency; mention limitation (2ⁿ rows; no objects/quantifiers) leading to theorem proving and FOL.

---

# 9. PROBLEM BANK WITH DETAILED SOLUTIONS

**9.1 Truth tables:** see Section 3.5, Problems 1 to 6.

**9.2 Logical equivalence problems**

*(a) Show P→Q ≡ ¬Q→¬P (contraposition).* ¬Q→¬P ≡ ¬(¬Q)∨¬P (implication elimination) ≡ Q∨¬P (double negation) ≡ ¬P∨Q (commutativity) ≡ P→Q ✔.

*(b) Show ¬(P→Q) ≡ P∧¬Q.* ¬(¬P∨Q) ≡ ¬¬P∧¬Q ≡ P∧¬Q ✔. (Useful: the only way an implication fails.)

*(c) Show P→(Q→R) ≡ (P∧Q)→R.* LHS ≡ ¬P∨(¬Q∨R) = ¬P∨¬Q∨R. RHS ≡ ¬(P∧Q)∨R ≡ (¬P∨¬Q)∨R = ¬P∨¬Q∨R ✔.

*(d) Show P↔Q ≡ (P∧Q)∨(¬P∧¬Q).* P↔Q ≡ (¬P∨Q)∧(¬Q∨P). Distribute: (¬P∧¬Q)∨(¬P∧P)∨(Q∧¬Q)∨(Q∧P) [expanding (¬P∨Q)∧(¬Q∨P) = (¬P∧¬Q)∨(¬P∧P)∨(Q∧¬Q)∨(Q∧P)]. The mixed terms are contradictions (F) and vanish → (¬P∧¬Q)∨(P∧Q) ✔. (Or verify by truth table: both columns are T in rows TT and FF only.)

**9.3 Entailment problems**

*(a) {P→Q, Q} ⊨ P?* No. Counter-model: P=F, Q=T makes KB true and P false.
*(b) {P∨Q, ¬Q∨R} ⊨ P∨R?* Yes. Suppose P∨R false: P=F, R=F. P∨Q forces Q=T; then ¬Q∨R = F∨F = F, KB false. So no model has KB true and P∨R false. (Resolution gives this directly: resolve on Q.)
*(c) {P∧Q} ⊨ P∨R?* Yes: in any model where P∧Q is true, P is true so P∨R is true.
*(d) {P→Q, ¬Q} ⊨ ¬P?* Yes (Modus Tollens). Models of KB: P→Q needs P=F or Q=T; ¬Q needs Q=F; so P=F; ¬P true ✔.

**9.4 Modus Ponens problems**

*(a) Given A→B, B→C, A. Derive C.* B (MP 1,3); C (MP 2, B).
*(b) Given: "If I study, I pass. If I pass, I get a degree. I study." Let S, P, D. S→P, P→D, S ⊢ D.* P (MP), D (MP).
*(c) Given (A∧B)→C, C→D, A, B. Derive D.* A∧B; C (MP); D (MP).

**9.5 Resolution problems:** Section 4.5 problems R1 to R5.

**One more with a conversion step. KB: P↔Q, P. Prove Q.**
P↔Q ≡ (¬P∨Q)∧(¬Q∨P). Clauses: C1 ¬P∨Q; C2 ¬Q∨P; C3 P; negated goal C4 ¬Q. C5 Q (C1,C3); C6 ⊥ (C5,C4). **Proved.**

**9.6 CNF problems:** Section 4.7, C1 to C7.

**9.7 Horn clause identification**

| Clause | Positive literals | Horn? | Type |
|---|---|---|---|
| ¬A∨¬B∨C | 1 | Yes | definite (rule) |
| A | 1 | Yes | fact |
| A∨B | 2 | No | |
| ¬A∨¬B | 0 | Yes | goal |
| ¬A∨B∨C | 2 | No | |
| (A∧B)→C | converts to ¬A∨¬B∨C | Yes | rule |
| A→(B∨C) | ¬A∨B∨C: 2 | No | |

**9.8 FOL translation problems:** Section 6.7 (22 sentences). Extra reverse-direction practice: translate `∀x (Dog(x) → Animal(x))` → "Every dog is an animal"; `∃x (Dog(x) ∧ Barks(x))` → "Some dog barks"; `∀x ∃y Loves(x,y)` → "Everyone loves someone"; `¬∃x (Dog(x) ∧ Flies(x))` → "No dog flies".

---

# 10. QUICK DEFINITIONS SHEET (simple / formal / example)

| Term | Simple | Formal | Example |
|---|---|---|---|
| Knowledge Base | notebook of facts/rules | set of sentences in a formal KR language | {Rain→Wet, Rain} |
| Knowledge-Based System | program using KB + reasoning | system with KB and inference engine | expert system |
| Model | one possible world | assignment of truth values to all symbols (satisfying α ⇒ model of α) | P=T,Q=F |
| KB Agent | agent with a notebook | agent using TELL/ASK on a KB to act | Wumpus agent |
| TELL / ASK | write / query | add sentence / query entailed knowledge | TELL(KB, Breeze) |
| Proposition | true/false statement | declarative sentence with truth value | "It rains" |
| Syntax | grammar | rules for well-formed sentences | P∧Q legal |
| Semantics | meaning | truth of sentences in a model | P∧Q T iff both T |
| Connective | logical glue | ¬, ∧, ∨, →, ↔ | P→Q |
| Truth table | list of all cases | table of truth values over all 2ⁿ models | see 3.4 |
| Logical equivalence | same meaning | α≡β iff same value in all models | P→Q ≡ ¬P∨Q |
| Tautology / Valid | always true | true in all models | P∨¬P |
| Contradiction / Unsat. | always false | true in no model | P∧¬P |
| Contingency | sometimes true | satisfiable, not valid | P→Q |
| Satisfiable | can be true | true in ≥1 model | P∧Q |
| Entailment | must follow | KB ⊨ α iff α true in all models of KB | {P,P→Q} ⊨ Q |
| Inference | derive by rules | KB ⊢ᵢ α by procedure i | MP, resolution |
| Soundness | no false conclusions | ⊢ ⇒ ⊨ | Resolution |
| Completeness | no missed conclusions | ⊨ ⇒ ⊢ | Resolution refutation |
| Theorem proving | prove by rules | derive α from KB without enumerating models | proof of Q |
| Proof by contradiction | assume opposite, get absurdity | KB∧¬α unsatisfiable ⇒ KB ⊨ α | R1 |
| Modus Ponens | if-then rule application | α→β, α ⊢ β | rain → wet |
| Literal | symbol or its negation | atomic sentence or negation | ¬P |
| Clause | OR of literals | disjunction of literals | P∨¬Q |
| Resolution | cancel opposites | (A∨B),(¬A∨C) ⊢ (B∨C) | P∨Q, ¬P∨R ⊢ Q∨R |
| Empty clause | contradiction marker | clause with no literals, always false | ⊥ |
| Horn clause | rule-like clause | ≤1 positive literal | ¬A∨¬B∨C |
| Definite clause | rule | exactly 1 positive literal | ¬A∨B |
| CNF | AND of ORs | conjunction of clauses | (P∨Q)∧¬R |
| FOL | logic with objects and quantifiers | language of predicates, functions, constants, variables, quantifiers | ∀x Human(x)→Mortal(x) |
| Object | a thing | element of the domain | Socrates |
| Relation | link/property | set of tuples over the domain | Loves(Ram,Sita) |
| Function | maps to an object | maps tuples of objects to an object | MotherOf(Ram) |
| Constant | name of an object | symbol interpreted as one object | Ram |
| Variable | placeholder | symbol ranging over domain | x |
| Predicate | statement about objects | symbol interpreted as relation; gives T/F | Student(x) |
| ∀ | for all | true if P holds for every domain object | ∀x Human(x)→Mortal(x) |
| ∃ | exists | true if P holds for some object | ∃x Student(x)∧Smart(x) |
| Domain of discourse | the universe of objects | non-empty set quantifiers range over | all students |
| Interpretation | meaning assignment | maps symbols to domain objects/relations/functions | Likes={(A,B)} |
| FOL Model | interpretation making KB true | interpretation in which all KB sentences hold | |
| Free variable | unbound variable | not within scope of quantifier for it | y in ∀x P(x,y) |
| Bound variable | variable under a quantifier | within scope of its quantifier | x in ∀x P(x) |
| Scope | what a quantifier covers | the sentence it applies to | `∃x (P(x)∧Q(x))` |
| FOL KB | FOL notebook | set of FOL sentences (facts and rules) | family KB |

---

# 11. LAST-30-MINUTES REVISION SHEET (🔴 read this just before the exam)

**Truth tables**
```
P Q | ¬P  P∧Q  P∨Q  P→Q  P↔Q
T T |  F    T    T    T    T
T F |  F    F    T    F    F
F T |  T    F    T    T    F
F F |  T    F    F    T    T
```
Rows = 2ⁿ. All T = tautology; all F = contradiction; mixed = contingency.

**Equivalences:** α→β ≡ ¬α∨β ≡ ¬β→¬α · α↔β ≡ (α→β)∧(β→α) · ¬(α∧β) ≡ ¬α∨¬β · ¬(α∨β) ≡ ¬α∧¬β · ¬¬α ≡ α · α∨(β∧γ) ≡ (α∨β)∧(α∨γ) · ¬(α→β) ≡ α∧¬β.

**Definitions in one line:** Entailment: KB ⊨ α iff α true in all models of KB. Sound: ⊢ ⇒ ⊨. Complete: ⊨ ⇒ ⊢. Valid: true in all models. Satisfiable: true in ≥1 model. α valid ⇔ ¬α unsat. KB ⊨ α ⇔ KB∧¬α unsat.

**Inference rules:** MP: α→β, α ⊢ β. Modus Tollens: α→β, ¬β ⊢ ¬α. And-intro: α, β ⊢ α∧β. Resolution: (A∨B),(¬A∨C) ⊢ (B∨C); (P),(¬P) ⊢ ⊥. UI: ∀x P(x) ⊢ P(a).

**CNF procedure:** (1) kill ↔ (2) kill → (3) push ¬ in (De Morgan, ¬¬) (4) distribute ∨ over ∧ (5) tidy.

**Resolution procedure:** CNF the KB → add CNF of **¬goal** → resolve one complementary pair at a time → get ⊥ ⇒ proved; nothing new and no ⊥ ⇒ not entailed.

**Horn:** ≤ 1 positive literal. Definite = exactly 1. Fact = single positive. Goal = no positive. Rule: ¬A∨¬B∨C ≡ A∧B→C.

**KB agent loop:** TELL(percept) → ASK(action) → TELL(action) → act. Parts: KB + inference engine.

**FOL**
- Constant = object name; Variable = placeholder; Function → object; Predicate → T/F.
- **∀ with →; ∃ with ∧.**
- ¬∀x P ≡ ∃x ¬P; ¬∃x P ≡ ∀x ¬P.
- "No A is B" = ¬∃x (A∧B) = ∀x (A→¬B). "Only A are B" = ∀x (B→A).
- ∀x∃y ≠ ∃y∀x.
- Sentence = no free variables. Scope = brackets.
- Interpretation = meaning assignment over a domain; Model = interpretation making sentence true.

**PL vs FOL:** FOL adds objects, relations, functions, quantifiers.

**Common exam mistakes**
1. Writing P→Q as false when P is false (it is **true**).
2. Not negating the goal in resolution.
3. Resolving two pairs at once (P∨Q with ¬P∨¬Q).
4. De Morgan without flipping ∧/∨.
5. Leaving →/↔ in the final CNF.
6. ∀ with ∧, or ∃ with →.
7. Treating P→Q and Q→P as equivalent.
8. Mixing ⊨ and ⊢ in soundness/completeness.
9. Forgetting to show the step-by-step working (marks are for steps).
10. Free variables left in an FOL translation.

**Exam technique:** In 2-marks give definition + one example. In 5-marks give definition, key table/diagram, one example. In problems write every step with the rule name. Draw tables with a ruler. Underline final answers.

*Good luck. Your highest-return practice in the remaining time: truth table problem 6, CNF C6/C7, resolution R3/R4, and FOL sentences 4, 5, 7, 16.*
