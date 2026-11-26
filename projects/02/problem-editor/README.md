# Repo content for now

- `README.md`: This file ;)

- `spec`: Specification files for different things:
    1. Models: model problems that illustrate different kinds of problems and
       their file structure.
    2. `constitucio.md`: A root document giving directives for the whole
       enterprise.
    3. `problema-jutge.md`: Super-detailed and succint explanation of the
       structure of a problem, together with checklists for the AI to review at
       the end.

- `skills`: Skills for different commands for terminal-based code tools. Those
  are called like `/command-name`. Some of them are related to documentation
  generation, not problem generation. Ignore those, I guess.

All of this is in Catalan, but any AI can do a very good job of translating it
into English or Persian, so I guess that is not a problem anymore... 😉

# Goal

The main goal is to develop an application that helps users of the Jutge.org
platform (especially teachers) to create new problems.

Right now the process is too complicated for the majority of teachers and we
want them to be able to create new problems very easily, so that more problems
are created in the platform.

# Proposed Idea

A web interface in the style of a SaaS (think Google Docs), in which users just
sign-in and have their stuff (basically, a list of problems).

Some users will want to download stuff and not only keep copies of their
problems in the app, so it has to be easy to satisfy those, by making it trivial
to download problem folders, or uploading them.

For the general user, there is a "graphical editor", with a level of detail that
will probably grow in time (low detail in the beginning and high detail later
on), so that the user can visualize a problem in its entirety and also each
part: statement, solution (and wrong submissions along with their verdicts), 
test cases, test case generators, and all the settings of a problem.

The editor should allow basic edition, but the main point is to make a bottom
text-box send prompts to an AI agent (with the skills and specs preloaded), that
will operate on the files of the problem in behalf of the user.

# MCP or CLI

The system will be much more robust and trustworthy if the AI interacts with a
CLI that will report on the success or failure of each command, so that the AI
can correct mistakes and get feedback on each step. Commands on that tool should
be the different aspects that the user can change about a problem, or the checks
that the user wants to make on the testcases, etc. 

# AI or not AI

Sometimes, if AI is not really needed, we will not use it. If some operation is
very easy to do in code, we will program it in code to remove the
"probabilistic" component of AI. I don't have particular examples of this right
now but in time we will, I guess.

# Proposed Phases

1. Learn the problem format (there are many examples in the `spec/models`). Also
   the `problema-jutge.md` file is quite detailed, both for the AI and for
   humans.

2. Use the skills to generate new problems to get a feeling about the process,
   what are the steps in problem creation, what operations are more necessary,
   etc. All of this using Claude Code, `codex`, `opencode`, `pi` or whatever TUI
   you use. I would not use `codex` since they spy on you... probably `claude`
   as well. 

3. Scaffold a website (NextJS) in which you can do the same thing you did with
   the terminal and a very basic graphical representation is shown to the user.

4. Iterate both on the presentation, the available commands, and the whole
   robustness of the system until we can release.
